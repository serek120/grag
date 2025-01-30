#include <iostream>
#include <cstdio>
#include "potrzebne.cpp"

int main()
{
    game::time::DelayedPrinter printer(40);
    printer.printWithDelay("witaj w grze `nadal jej nie nazwalem` jest to tekstowa gra RPG pisana na `kolanie`");


    return 0;
}

