#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "game.h"
#include <string.h>

int8_t choice = 0;
const char options[MAX_ITEMS][MAX_STRINGLEN] = {
    "Start Game",
    "Options",
    "Exit"
};

void display_menu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("=== MineCweeper ===\n");
    for (int8_t i = 0; i < MAX_ITEMS; i++) {
        printf("[%c] %s\n", (choice == i) ? '>' : '\0', options[i]);
    }
    printf("===================\n");
    printf("\nUse W/S (down/up arrow) to navigate, Enter to select.\nQ to quit.\n");
}

int main() {

    while (1 || choice != Q_KEY_PRESSED)
    {
        display_menu();
        userinputkey = _getch();

        switch (userinputkey)
        {
            case W_KEY_PRESSED:
                choice = (choice == 0) ? 2 : choice - 1;
                break;
            case S_KEY_PRESSED:
                choice = (choice == 2) ? 0 : choice + 1;
                break;
        }
    }

    return 0;
}
