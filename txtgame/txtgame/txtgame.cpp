#include <iostream>
#include <cstdio>
#include "namespace.hpp"
#include "klasyitd.cpp"
#include "booleans.cpp"
#include "Windows.h"
#include <shellapi.h>


std::string userinput;
char buffer[256];

int static characterdesign() {
    game::DelayedPrinter printer(30);
    printer.printWithDelay("----Race you choose may unlock or block some dialogues in the game----");
    printer.printWithDelay("there are two main races dominant among humans, you can choose what race you are");
    printer.printWithDelay("Are you a \033[1;35;47m'Thiren'\033[0m");
    printer.printWithDelay("\033[1;32;47mor\033[0m");
    printer.printWithDelay("you are a \033[1;31;47m'Human'\033[0m");
    while (true) {
        printf("> :");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Invalid input");
            continue;
        } else {
            printf("Invalid input");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "Thiren") == 0) {
            printer.printWithDelay("You chose Thiren");
            g_bisthiren = true;
            game::sequence(4, 1);
            continue;
        } else if (strcmp(buffer, "Human") == 0) {
            printer.printWithDelay("You chose Human");
            g_bisHuman = true;
        }

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
            game::sequence(1, 4);
            return characterdesign();
        } else if (strcmp(buffer, "Exit") == 0) {
            break;
        } else if (strcmp(buffer, "ellen joe") == 0) {
            game::sequence(3, 1);
            ShellExecute(0, 0, L"https://i.imgur.com/LlgUaHi.jpeg", 0, 0, SW_SHOW);
            game::DelayedPrinter printer(700);
            printer.printWithDelay("You found an easter egg.");
            std::exit(0x000202);
        } else {
            printf("Invalid input. Please type 'Start' or 'Exit'.\n");
        }
    }

    return 0;
}
