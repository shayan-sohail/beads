#include <iostream>
#include "other.h"
#include "../../logger/logger.h"

LogStream System("System"), Network("Network"), Timer("Timer");

int main()
{
    log() << "Test Example\n";
    LogStream::default_stdout = false;
    log() << "Hello False\n";
    log() << "Hello False\n";
    log() << "Hello False\n";
    LogStream::default_stdout = true;
    log() << "Hello True\n";
    log() << "Hello True\n";
    log(System, WARNING) << "System Warning" << std::endl;
    log(Network, SUCCESS) << "Network Success" << std::endl;
    log(Timer, ERROR) << "Timer Error" << std::endl;
    printOtherLogs();
    return 0;
}