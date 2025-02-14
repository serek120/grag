#include <iostream>
#include <cstdio>
#include "namespace.hpp"
#include "klasyitd.cpp"

std::string userinput;

unsigned char userin222;

int prologue() {
    printf("yupeeeeee");
    return 0;
}


int main() {
    game::DelayedPrinter printer(5);
    printer.printWithDelay("witaj w grze \033[1;32;41m`nadal jej nie nazwalem`\033[0m jest to tekstowa gra RPG pisana na t. zw. \033[35m`kolanie`\033[0m");
pisanie:

    
    char buffer[256];
    scanf_s("%255s", buffer, (unsigned)_countof(buffer));
    buffer[255] = '\0'; // Ensure the buffer is null-terminated
    userinput = buffer;


    if (userinput == "Start") {
        game::sequence();
        return prologue();
    } else if (userinput == "wylacz") {
        system("exit");
    } else
        goto pisanie;
        /*
    std::cin >> userinput;

    if (userinput == "start") {
        game::loading(2);
        game::cls(2);
        return prologue();
    } else if (userinput == "wylacz") {
        game::cls(1);
        system("exit");
    }
    else
        goto pisanie;*/

    return 0;
}