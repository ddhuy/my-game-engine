#include "Logger.h"
#include "spdlog/spdlog.h"
#include <iostream>

void Logger::Log(const std::string &message)
{
    spdlog::info(message.c_str());
}


void Logger::Err(const std::string &message)
{
    spdlog::error(message.c_str());
}
