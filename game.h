#pragma once

#include "src/include/declaration_file.h"
#include <conio.h>

#define Q_KEY_PRESSED(key) ((key = _getch()) == 'q' || key == 'Q')

#define W_KEY_PRESSED(key) ((key = _getch()) == 'w' || key == 'W')
#define A_KEY_PRESSED(key) ((key = _getch()) == 'a' || key == 'A')
#define S_KEY_PRESSED(key) ((key = _getch()) == 's' || key == 'S')
#define D_KEY_PRESSED(key) ((key = _getch()) == 'd' || key == 'D')