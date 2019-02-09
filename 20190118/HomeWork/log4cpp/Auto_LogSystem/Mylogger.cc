 ///
 /// @file    Mylogger.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-02-02 21:35:01
 ///
#include "Mylogger.h" 
#include<log4cpp/Category.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include <iostream>
using std::cout;
using std::endl;

namespace ykx
{
Mylogger * Mylogger::_mylogger = nullptr;

Mylogger * Mylogger::getMylogger()
{
	if(nullptr == _mylogger)
	{
			_mylogger = new Mylogger();
		}
	return _mylogger;
}
void Mylogger::destroy()
{
	if(_mylogger)
		delete _mylogger;
}

Mylogger::Mylogger()
	:_myCat(log4cpp::Category::getRoot().getInstance("MyCategory"))//返回引用堆空间
{
	using namespace log4cpp;
	cout << "Mylogger() " << endl;
	PatternLayout * ptn1 =new PatternLayout();
	ptn1->setConversionPattern("%d %c [%p] %m%n");

	PatternLayout * ptn2 =new PatternLayout();
	ptn2->setConversionPattern("%d %c [%p] %m%n");

	OstreamAppender * ostreamAppender = new OstreamAppender("console", &cout);
	ostreamAppender->setLayout(ptn1);

	FileAppender * fileAppender = new FileAppender("fileappender", "ykx.log");
	fileAppender->setLayout(ptn2);

	_myCat.addAppender(ostreamAppender);
	_myCat.addAppender(fileAppender);
	_myCat.setPriority(log4cpp::Priority::DEBUG);
}

Mylogger::~Mylogger()
{
cout<< "~Mylogger() " << endl;
log4cpp::Category::shutdown();
}
void Mylogger::setPriority(Priority p)
{										//自定义优先级
	switch(p)
	{
		case Priority::WARN:
			_myCat.setPriority(log4cpp::Priority::WARN);
			break;
		case Priority::ERROR:
			_myCat.setPriority(log4cpp::Priority::ERROR);
			break;
		case Priority::INFO:
			_myCat.setPriority(log4cpp::Priority::INFO);
			break;
		case Priority::DEBUG:
			_myCat.setPriority(log4cpp::Priority::DEBUG);
			break;
	}
	
}
}
