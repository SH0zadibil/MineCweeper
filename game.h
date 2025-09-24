#pragma once

#include "src/include/declaration_file.h"
#include <stdio.h>

int8_t choice = 0;
level lvl;
const char options[MAX_ITEMS][MAX_STRINGLEN] = {
    "EASY",
    "MEDIUM",
    "EXTREME"
};

void display_menu();
void config_game();

// <?> WINDOWS/LINUX KEY INPUT
// the "_getch" method
#ifdef _WIN32
    #include <conio.h> // _getch()
    char userinputkey;
#elif __linux__
    #include <unistd.h>
    #include <termios.h>
    int userinputkey;
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


int8_t choice = 0;
level lvl;
const char options[MAX_ITEMS][MAX_STRINGLEN] = {
    "Start Game",
    "Options",
    "Exit"
};

#define Q_KEY_PRESSED 'q'
#define W_KEY_PRESSED 'w'
#define A_KEY_PRESSED 'a'
#define S_KEY_PRESSED 's'
#define D_KEY_PRESSED 'd'