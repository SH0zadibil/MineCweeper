#pragma once

#include "src/include/declaration_file.h"
#include <stdio.h>

#ifdef _WIN32
    #include <conio.h> // _getch()
#elif __linux__
    #include <unistd.h>
    #include <termios.h>
    int _getch(void) {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

#define Q_KEY_PRESSED(key) ((key = _getch()) == 'q' || key == 'Q') // quit

#define W_KEY_PRESSED(key) ((key = _getch()) == 'w' || key == 'W') // up
#define A_KEY_PRESSED(key) ((key = _getch()) == 'a' || key == 'A') // left
#define S_KEY_PRESSED(key) ((key = _getch()) == 's' || key == 'S') // down
#define D_KEY_PRESSED(key) ((key = _getch()) == 'd' || key == 'D') // right