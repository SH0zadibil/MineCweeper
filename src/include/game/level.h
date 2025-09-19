#ifndef LEVEL_H
#define LEVEL_H

#include "difficulty.h"
#include "constants.h"
#include <stdbool.h>

typedef struct {
    bool initialized;
    char** map;
    char** closedmap;
} level;

char getCh(level* lvl, size_t x, size_t y);

bool isMine(level* lvl, char* ch);
bool isMineAt(level* lvl, size_t x, size_t y);
bool checkWin(level* lvl);
bool checkLose(level* lvl);

void genMap(level* lvl, levelDifficulty difficulty);
void regenMap(level* lvl, levelDifficulty difficulty);
void printMap(level* lvl, bool closedOrNot);
void revealcell(level* lvl, size_t x, size_t y);


#endif