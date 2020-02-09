 ///
 /// @file    tcp_server.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-12 20:25:30
 ///
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using namespace std;

void test0(void)
{
	int a = 1;
	char *p = (char *)&a;
	int b = (int)(*p);
	cout << "*p = "<< *p << endl;
	cout << "b = "<< b << endl;
	p += 3;
	cout << "after p += 3"<< endl;
	b = (int)(*p);
	cout << "b = "<< b << endl;
}
void test1()
{
	char buff[1024];//存在大端模式小段模式问题吗？
					//不存在，因为大端模式和小端模式只是针对于多字节的数据类型
	union test //联合体共享数据空间
	{
		int a;
		char data[4];
	};

	union test t1;
	t1.a = 1;
	int x = t1.data[0];
	int y = t1.data[3];
	//经测试，采用的小端模式进行存储（主机字节序）
	cout<< "x = "<< x << endl
		<< "y = "<< y << endl;
}

#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
} while(0)

void test2()
{
	//1.创建套接字,得到一个文件描述符
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1){
		ERROR_EXIT("select");
	}
	//网路模式采用大端模式	
	unsigned short port = 8888;
	string ip = "192.168.63.128";
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);//小端模式---->大端模式
	serveraddr.sin_addr.s_addr = inet_addr(ip.data());
	//2.绑定网络地址
	if(-1 == bind(listenfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr))){
		::close(listenfd);//在unistd空间中
		ERROR_EXIT("bind");
	}
	//3.对新连接请求进行监听
	if(-1 == ::listen(listenfd, 10)){
		::close(listenfd);
		ERROR_EXIT("listen");
	}

	while(1){
	//4.建立新连接
	cout << ">> server is about to accept a new link " << endl;
	struct sockaddr_in clientaddr;//解析对端IP和port
	//socklen_t len = 0;//有问题
	socklen_t len = sizeof(struct sockaddr_in);
	::memset(&clientaddr, 0, sizeof(struct sockaddr_in));
	int peerfd = ::accept(listenfd, (struct sockaddr*)&clientaddr, &len);
	if(peerfd == -1){
		::close(listenfd);
		ERROR_EXIT("accept");
	}//如果peerfd  > 0 说明连接建立完毕，
	//以后通过peerfd对应的数据结构与对端进行通信
	int ret = 0;
	if(ret == -1){
		perror("get peername");
	} else{
		cout <<"clientaddr len = "	<< len << endl;
		string clientip(inet_ntoa(clientaddr.sin_addr));
		unsigned short clientport = ntohs(clientaddr.sin_port);
		cout << ">> server" << ip <<":" << port << " -->  "
			 << "client " << clientip << ":" << clientport
			 << " has connected !"<< endl;
	}

	//5.进行数据的接受和发送
	
	char buff[1024] = {0};
	ret = ::recv(peerfd, buff, sizeof(buff), 0);
	if(ret < 0){
		if( -1 == ret && errno == EINTR)	
			continue;
		else
			ERROR_EXIT("recv");
	} else if(ret == 0){//连接已经断开了
		::close(peerfd);
	} else{
		//6.对接受到的数据进行处理
		
		cout << ">> server gets massage from client:"<< buff <<endl;
		
		//7.进行数据的发送,回显操作
		ret = ::send(peerfd, buff, strlen(buff), 0);
		if(ret == -1){
			ERROR_EXIT("send");
			::close(peerfd);
		}
	//断开连接
		::sleep(1);
		::close(peerfd);
	}
	}//end of while
	//关闭服务器的监听文件描述符	
	::close(listenfd);
}//end of test2()

int main(void)
{
	test2(); 
	return 0;
}
