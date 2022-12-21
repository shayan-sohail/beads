#include <iostream>
#include <signal.h>
#include "timer.h"

bool g_signal = true;
void firstCallback()
{
    std::cout << "First Callback" << std::endl;
}
void secondCallback()
{
    std::cout << "Second Callback" << std::endl;
}

void signal_handler(int signum)
{
    g_signal = false;
}
int main()
{
    signal(SIGINT, signal_handler);
    Timer T;
    T.add_singleshot(firstCallback, 3000);
    T.add_periodic(secondCallback, 1000);
    while (g_signal) {};

    return 0;
}