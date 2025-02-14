#include <iostream>
#include <cstdio>
#include "namespace.hpp"
#include "klasyitd.cpp"
#include "booleans.cpp"
#include "Windows.h"
#include <shellapi.h>

std::string userinput;
char buffer[256];

int characterdesign() {
    game::DelayedPrinter printer(30);
    printer.printWithDelay("there are two main races dominant among humans, you can choose what race you are");
    printer.printWithDelay("siema");

    while (true) {
        printf("> :");
    }

    return 0x1;
    
}

int main() {
    game::DelayedPrinter printer(1);
    printer.printWithDelay("Welcome to the game \033[1;32;41m`I still haven't named it`\033[0m, it is a text-based RPG written on the so-called \033[35m`knee`\033[0m");
    printer.printWithDelay("Type \033[1;32;41m`Start`\033[0m with a capital letter to start the game\nor \033[1;32;41m`Exit`\033[0m also with a capital letter to exit the game");
    while (true) {
        printf("> :");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Invalid input.\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "Start") == 0) {
            game::sequence();
            return characterdesign();
        } else if (strcmp(buffer, "Exit") == 0) {
            break;
        } else if (strcmp(buffer, "ellen joe") == 0) {
            ShellExecute(0, 0, L"http://www.google.com", 0, 0, SW_SHOW);
        } else {
            printf("Invalid input. Please type 'Start' or 'Exit'.\n");
        }
    }

    return 0;
}
