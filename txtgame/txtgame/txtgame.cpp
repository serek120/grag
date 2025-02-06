#include <iostream>
#include <cstdio>
#include "namespace.hpp"

int main()
{
    game::DelayedPrinter printer(5);
    printer.printWithDelay("witaj w grze \033[1;32;41m`nadal jej nie nazwalem`\033[0m jest to tekstowa gra RPG pisana na t. zw. \033[35m`kolanie`\033[0m");

    game::loading(2);

    printer.printWithDelay("Wyberz klase");

    printer.printWithDelay("Czlowiek\nLiso-czlowiek\n\nto tyle bo nie mam pomyslu na reszte");

    return 0;
}

