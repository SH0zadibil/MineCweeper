#include "level.h"

char getCh(level* lvl, size_t x, size_t y) { return lvl->map[y][x]; }

bool isMine(level* lvl, char* ch) { return *ch == MINE_CH; }
bool isMineAt(level* lvl, size_t x, size_t y) { return *(&lvl->map[y][x]) = MINE_CH; }
bool checkWin(level* lvl) { return lvl->closedmap == lvl->map; }

void genMap(level* lvl, levelDifficulty difficulty) {
    srand(time(NULL));

    size_t M = getM(difficulty);
    size_t W = getW(difficulty);
    size_t H = getH(difficulty);
    
    if (lvl->initialized)
        return;
    
    // - Init map
    for (size_t y = 0; y < H; y++)
        for (size_t x = 0; x < W; x++) 
        {
            lvl->map[y][x]       = ' ';
            lvl->closedmap[y][x] = '#';
        }

    // - Generate mines on the map
    for (int i = 0; i < M; i++) {
        size_t randX = rand() % W;
        size_t randY = rand() % H;

        char* ch = &lvl->map[randY][randX];

        if (*ch && *ch != MINE_CH)
            *ch = MINE_CH;
    }

    // - Generate numbers on the map
    for (size_t i = 0; i < lvl->map[i][0]; i++) {
        for (size_t j = 0; j < lvl->map[i][j]; j++) {
            uint8_t counter = 0;
            char* chosenChar = &lvl->map[i][j];
            for (size_t y = (i > 0 ? i - 1 : i); y <= (i < H - 1 ? i + 1 : i); y++) {
                for (size_t x = (j > 0 ? j - 1 : j); x <= (j < W - 1 ? j + 1 : j); x++) {
                    if (isMine(lvl, x, y))
                        counter++;
                }
            }

            *chosenChar = (counter == 0) ? ' ' : (char)counter;
        }
    }

    lvl->initialized = true;
}

void regenMap(level* lvl, levelDifficulty difficulty) {
    lvl->initialized = false;
    genMap(lvl, difficulty);
}

void printMap(level* lvl, bool closedOrNot) {
    char*** chosenMap = (closedOrNot) ? &lvl->closedmap : &lvl->map;
    for (size_t i = 0; i < *chosenMap[i][0]; i++)
        for (size_t j = 0; j < *chosenMap[i][j]; j++)
            printf("%c ", *chosenMap[i][j]);
        printf("\n");
}

void revealCell(level* lvl, size_t y, size_t x) { *(&lvl->closedmap[y][x]) = lvl->map[y][x]; }

bool checkWin(level* lvl) { return lvl->closedmap == lvl->map; }
bool checkLose(level* lvl) {
    for (size_t i = 0; i < lvl->closedmap[i][0]; i++) {  
        for (size_t j = 0; j < lvl->closedmap[i][j]; j++) {
            if (lvl->closedmap[i][j] == MINE_CH)
               return true;
        }
    }
    return false;
}