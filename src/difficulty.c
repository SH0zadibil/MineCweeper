#include "include/game/difficulty.h"
#include "include/game/constants.h"

levelDifficulty getDifficultyFromInput(const size_t input) {
    return (levelDifficulty)input;
}

void setDiffictultyFromInput(levelDifficulty* level, const size_t input) {
    *level = (levelDifficulty)input;
}

size_t getW(levelDifficulty level) {
    switch (level) 
    {
        case 1: return  EASY_W;
        case 2: return  MEDIUM_W;
        case 3: return  EXTREME_W;
        default: return EASY_W;
    }
}
size_t getH(levelDifficulty level) {
    switch (level) 
    {
        case 1: return  EASY_H;
        case 2: return  MEDIUM_H;
        case 3: return  EXTREME_H;
        default: return EASY_H;
    }
}
size_t getM(levelDifficulty level) {
    switch (level) 
    {
        case 1: return  EASY_MINES;
        case 2: return  MEDIUM_MINES;
        case 3: return  EXTREME_MINES;
        default: return EASY_MINES;
    }
}