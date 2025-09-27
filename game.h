#pragma once

#include "src/include/declaration_file.h"
#include <stdint.h>
#include <stdio.h>

extern int8_t choice;
extern level lvl;
extern const char options[MAX_ITEMS][MAX_STRINGLEN];

void display_menu();
void config_game();

// <?> WINDOWS/LINUX KEY INPUT
// the "_getch" method
#ifdef _WIN32
    #include <conio.h> // _getch()
    #define ENTER 13
    char userinputkey;
#elif __linux__
    #include <unistd.h>
    #include <termios.h>
    #define ENTER 10
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

#define Q 'q'
#define W 'w'
#define A 'a'
#define S 's'
#define D 'd'