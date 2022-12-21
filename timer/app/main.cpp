#include <iostream>
#include "timer.h"

void firstCallback()
{
    std::cout << "First Callback" << std::endl;
}
void secondCallback()
{
    std::cout << "Second Callback" << std::endl;
}

int main()
{
    {
        Timer T;
        T.add_periodic(firstCallback, 1000);
        T.add_periodic(secondCallback, 1000);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        T.remove(firstCallback);
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}