#include <stdio.h>
#include "game.h"

int main() {
    while (1 || choice != Q)
    {
        display_menu();
        userinputkey = _getch();

        switch (userinputkey)
        {
            case W:
                choice = (choice == 0) ? 2 : choice - 1;
                break;
            case S:
                choice = (choice == 2) ? 0 : choice + 1;
                break;
            case ENTER:
                config_game();
                printMap(&lvl, true);
                printf("\n\n");
                return 0;
        }
    }
    
    return 0;
}
