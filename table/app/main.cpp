#include <iostream>
#include "table.h"

int main()
{
    table mtable;
    mtable.add_field<int>("Serial");
    mtable.add_field<int>("Serial1");
    mtable.add_field<float>("Serial2");
    mtable.add_field<char>("Serial3");
    int a = 2;
    mtable.insert<int>("Serial1", a);
}