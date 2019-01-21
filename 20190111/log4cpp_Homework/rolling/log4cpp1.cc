 ///
 /// @file    log4cpp1.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-21 19:53:31
 ///
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh> 
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <iostream> 
using std::cout;
using std::endl;
using namespace log4cpp;
 
void test1()
{
	//控制日志输出格式
	PatternLayout * patternLayout1 = new PatternLayout();
	patternLayout1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * patternLayout2 = new PatternLayout();
	patternLayout2->setConversionPattern("%d %c [%p] %m%n");
	//指定输出的目的地
	OstreamAppender * ostreamAppender = new OstreamAppender("console",&cout);
	ostreamAppender->setLayout(patternLayout1);
	
	//使用Rollwing fileAppend 可以拆分日志的大小
	RollingFileAppender * rollingFileAppender = 
		new RollingFileAppender("rollingFileAppender",
				"rollingwd.log",
				5 * 1024,//大小
				3);//备份文件数量
	rollingFileAppender->setLayout(patternLayout2);

	//FileAppender*fileAppender = new FileAppender("fileAppender","wd.log");
	//fileAppender-> setLayout(patternLayout2);

	//日志记录器
	Category & myCat = Category::getRoot().getInstance("myCat");

		myCat.addAppender(ostreamAppender);
		myCat.addAppender(rollingFileAppender);
		myCat.setPriority(Priority::DEBUG);//这里设置不同的级别
//		myCat.setPriority(Priority::ERROR);//这里设置不同的级别 记录日志
											//只有当每一条日志的优先级大于Category的优先级时才会记录
	//执行记录日志的操作
	for(int idx = 0; idx != 100; ++idx){
		myCat.emerg("this is an emerg message");
		myCat.fatal("this is an fatal message");
		myCat.alert("this is an alert message");
		myCat.error("this is an error message");
		myCat.info("this is an info message");
		myCat.crit("this is an crit message");
		myCat.debug("this is an debug message");
		myCat.notice("this is an notice message");
		myCat.warn("this is an warn message");
		//回收内存
    }
		Category::shutdown(); 
}

int main()
{
	test1();
	return 0;
}




