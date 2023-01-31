#include "other.h"

LogStream Other;

void printOtherLogs()
{
    log(Other, INFO) << "This message is from Other" << std::endl;
}