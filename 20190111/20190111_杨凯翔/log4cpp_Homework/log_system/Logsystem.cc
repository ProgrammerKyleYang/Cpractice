 ///
 /// @file    Logsystem.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-22 08:31:54
 ///
#include "Logsystem.h"
#include <log4cpp/Category.hh> 
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
	Logsystem * Logsystem::_pInstance = nullptr;

	Logsystem * Logsystem::getInstance() 
	{
		if(nullptr == _pInstance) {
				_pInstance = new Logsystem();
			}
		return _pInstance;
	}

    void Logsystem::destory()
	{
		if(_pInstance) {
				delete _pInstance;
			}
	}
	
	Logsystem:: Logsystem()
	: _mycat( log4cpp::Category::getRoot().getInstance("Category"))
	{
		using namespace log4cpp;//把使用限制在一定的范围里
		PatternLayout * ptn1 = new PatternLayout();
		ptn1->setConversionPattern("%d %c [%p] %m%n");

		PatternLayout * ptn2 = new PatternLayout();
		ptn2->setConversionPattern("%d %c [%p] %m%n");

		OstreamAppender * ostreamAppender = new OstreamAppender("OstreamAppender", &cout);
		ostreamAppender->setLayout(ptn1);

		FileAppender * fileAppender = new FileAppender("FileAppender", "wd.log");
		fileAppender->setLayout(ptn2);

		_mycat.addAppender(ostreamAppender);
		_mycat.addAppender(fileAppender);
		_mycat.setPriority(log4cpp::Priority::DEBUG);
		cout << "log()" << endl;

	}
	
	Logsystem::	~Logsystem()
	{
		cout << "~log()" << endl;
		log4cpp::Category::shutdown();

	}
	void Logsystem::warn(const char * msg)
	{
		_mycat.warn(msg);
	}
	void Logsystem::error(const char *msg)
	{
		_mycat.error(msg);
	}
	void Logsystem::info(const char *msg)
	{
		_mycat.info(msg);
	}
	void Logsystem::debug(const char *msg)
	{
		_mycat.debug(msg);
	}
	void Logsystem::setPriority(Priority p)
	{
		switch(p)
		{
			case WARN:
				_mycat.setPriority(log4cpp::Priority::WARN);
				break;
			case ERROR:
				_mycat.setPriority(log4cpp::Priority::ERROR);
				break;
			case INFO:
				_mycat.setPriority(log4cpp::Priority::INFO);
				break;
			case DEBUG:
				_mycat.setPriority(log4cpp::Priority::DEBUG);
				break;
		}
	}
}
