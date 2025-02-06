#include <iostream>
#include <cstdio>
#include "namespace.hpp"
#include "klasyitd.cpp"

char userinput;

int main()
{
    game::DelayedPrinter printer(5);
    printer.printWithDelay("witaj w grze \033[1;32;41m`nadal jej nie nazwalem`\033[0m jest to tekstowa gra RPG pisana na t. zw. \033[35m`kolanie`\033[0m");
    
    scanf_s("%c", userinput );

    game::loading(2);  

    return 0;
}

