#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "game.h"

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
