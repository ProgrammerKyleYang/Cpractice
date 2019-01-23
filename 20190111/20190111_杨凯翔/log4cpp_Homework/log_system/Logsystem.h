 ///
 /// @file    Logsystem.h
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-22 08:32:04
 ///
#ifndef __WD_LOGSYSTEM_H__
#define __WD_LOGSYSTEM_H__
#include <log4cpp/Category.hh> 
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;

namespace wd
{ 
	class Logsystem
	{
	public:
		enum Priority {
			ERROR = 300,
			WARN,
			INFO,
			DEBUG
		};
	public:
		static Logsystem *getInstance();
		void destory();
		void warn(const char *msg);
		void error(const char *msg);
		void info(const char *msg);
		void debug(const char *msg);
		void setPriority(Priority p);
	
	private:
		Logsystem();
		~Logsystem();
	
	private:
		log4cpp::Category &_mycat;
		static Logsystem *_pInstance;
	
	};

#define prefix(msg) string("[")\
	.append(__FILE__).append(":")\
	.append(__FUNCTION__).append(":")\
	.append(std::to_string(__LINE__)).append("] ")\
	.append(msg).c_str()

#define LogError(msg) Logsystem::getInstance()->error(prefix(msg))
#define LogWarn(msg) Logsystem::getInstance()->warn(prefix(msg))
#define LogInfo(msg) Logsystem::getInstance()->info(prefix(msg))
#define LogDebug(msg) Logsystem::getInstance()->debug(prefix(msg))

}
#endif
