 ///
 /// @file    tcp_client.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-14 18:11:40
 ///
#include <unistd.h>
#include <stdio.h>
#include <error.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;

//宏定义
#define ERROR_EXIT(msg) do{\
	::perror(msg);\
	::exit(EXIT_FAILURE);\
}while(0)

void test0(void)
{
	while(1){
	
		//1.创建客户端套接字
		int clientfd = ::socket(AF_INET, SOCK_STREAM, 0);
		if(clientfd == -1){
			ERROR_EXIT("socket");
			return ;
		} 

		struct sockaddr_in serveraddr;
		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(8888);
		serveraddr.sin_addr.s_addr = ::inet_addr("192.168.63.128");

		//2.客户端发起连接请求
		cout << ">>client is about to connect server..."<< endl;
		int ret = ::connect(
			clientfd,
			(const struct sockaddr*)&serveraddr,
			sizeof(serveraddr)); 
		if(ret == -1){
			ERROR_EXIT("connect");
			::close(clientfd);
		}

		//3.建立好连接之后，发送数据
		cout << " >> client and server has connected!" << endl;
		cout << " >> please input some data:" << endl;
		string data;
		cin >> data;

		//4.向服务器发送业务请求
		ret = ::send(clientfd, data.c_str(), data.size(), 0);
		if(ret == -1){
			ERROR_EXIT("send");
			close(clientfd);
		}

		//5.接受服务器返回的数据
		char buff[1024] = {0};//客户端应用层缓冲区
		ret = ::recv(clientfd, buff, sizeof(buff), 0);
		//针对recv的三种返回值情况都要进行判断
		if(ret == -1){//出错则报错并关闭连接
			ERROR_EXIT("recv");
			::close(clientfd);
			return;
		}else if(ret == 0){//断开连接
			::close(clientfd);	
		}else{
			cout <<">> client receive"<< ret << "bytess data."<< endl;
			cout << ">> receive data: "<< buff << endl;
		} 
		
		//6.断开连接
		::close(clientfd);
	}//while
}


int main(void)
{
	test0();
	return 0;
}
