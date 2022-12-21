#include <iostream>
#include "logger.h"

LogStream System("System"), Network("Network"), Timer("Timer");

int main()
{
    log() << "Hello World\n";
    LogStream::default_stdout = false;
    log() << "Hello False\n";
    log() << "Hello False\n";
    log() << "Hello False\n";
    LogStream::default_stdout = true;
    log() << "Hello True\n";
    log() << "Hello True\n";
    return 0;
}