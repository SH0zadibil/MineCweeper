#pragma once

#include "src/include/declaration_file.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

extern int8_t choice;
extern level lvl;
extern const char options[MAX_ITEMS][MAX_STRINGLEN];

void display_menu();
void config_game() ;
int listenKey()    ;

#ifdef _WIN32
    #define ENTER 13
#endif
#ifdef __linux__
    #define ENTER 10
    int _getch(void);
#endif

#define Q 'q' // 0x27
#define W 'w' // 0x57
#define A 'a' // 0x41
#define S 's' // 0x53
#define D 'd' // 0x44