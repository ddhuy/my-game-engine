#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

class Logger
{
public:
    static void Log(const std::string &message);
    static void Err(const std::string &message);
};

#endif // __LOGGER_H__