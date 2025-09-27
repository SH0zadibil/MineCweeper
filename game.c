#include <stdint.h>
#include <stdlib.h>
#include "game.h"

// Ensure 'level' is defined before this line, either in game.h or above.
int8_t choice = 0;
level lvl;
const char options[MAX_ITEMS][MAX_STRINGLEN] =
{
    "EASY",
    "MEDIUM",
    "EXTREME"
};

void display_menu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("=== MineCweeper ===\n");
    for (size_t i = 0; i < MAX_ITEMS; i++) {
        printf("[%c] %s\n", (choice == i) ? '>' : '\0', options[i]);
    }
    printf("===================\n");
    printf("\nUse: W/S (down/up arrow) to navigate, Enter to select.\nQ to quit.\n");
}

void config_game() {
    regenMap(&lvl, getDifficultyFromInput(userinputkey));
}