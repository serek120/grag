#include <iostream>
#include <cstdio>
#include "namespace.hpp"

int main()
{
    game::DelayedPrinter printer(5);
    printer.printWithDelay("witaj w grze \033[32m`nadal jej nie nazwalem`\033[0m jest to tekstowa gra RPG pisana na t. zw. \033[35m`kolanie`\033[0m");

    game::loading(5);


    return 0;
}

