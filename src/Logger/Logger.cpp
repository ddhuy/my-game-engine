#include "Logger.h"
extern "C" {
#include "rxi/log.h"
}
#include <iostream>

void Logger::Log(const std::string &message)
{
    log_info(message.c_str());
}


void Logger::Err(const std::string &message)
{
    log_error(message.c_str());
}
