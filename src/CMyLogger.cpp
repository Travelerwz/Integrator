#include "CMyLogger.h"

Intergrator::CMyLogger::CMyLogger()
{
    log4cplus::initialize();
    //std::cout<<MY_LOG_PATH<<std::endl;
    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(MY_LOG_PATH));
    //logger = Logger::getRoot();
    logger = Logger::getRoot();
}
Intergrator::CMyLogger::~CMyLogger()
{

}

Intergrator::CMyLogger& Intergrator::CMyLogger::Instance()
{
    static CMyLogger log;
    return log;
}

void Intergrator::CMyLogger::Debug(std::string str)
{
    if(str.empty())
    {
        return ;
    }
    LOG4CPLUS_DEBUG(logger,str.c_str());
    return ;
}
void Intergrator::CMyLogger::Error(std::string str)
{
    if(str.empty())
    {
        return ;
    }
    LOG4CPLUS_ERROR(logger,str.c_str());
    return ;
}

void Intergrator::CMyLogger::Info(std::string str)
{
    if(str.empty())
    {
        return ;
    }
    LOG4CPLUS_INFO(logger,str.c_str());
    return ;
}

void Intergrator::CMyLogger::Warn(std::string str)
{
    if(str.empty())
    {
        return ;
    }
    LOG4CPLUS_WARN(logger,str.c_str());
    return ;
}

void Intergrator::CMyLogger::Fatal(std::string str)
{
    if(str.empty())
    {
        return ;
    }
    LOG4CPLUS_FATAL(logger,str.c_str());
    return ;
}
