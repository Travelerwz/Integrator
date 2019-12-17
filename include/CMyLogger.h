#pragma once

#include <iostream>
#include <log4cplus/appender.h>
#include <log4cplus/logger.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
#include <cstdlib>

using namespace log4cplus;
using namespace log4cplus::helpers;

#define MY_LOG_PATH  "../config/logconfig.properites"

namespace Intergrator{

class CMyLogger
{
public:
    static CMyLogger& Instance();
    Logger logger;
    void Debug(std::string str);
    void Info(std::string str);
    void Warn(std::string str);
    void Fatal(std::string str);
    void Error(std::string str);

private:
    CMyLogger();
    ~CMyLogger();
};

#define LOGCPP CMyLogger::Instance()
}