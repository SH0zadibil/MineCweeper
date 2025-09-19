#ifndef GAME_DIFFICULTY_H
#define GAME_DIFFICULTY_H

#include <stdint.h> // uint_8t

typedef enum {
    EASY_LEVEL    = 1,
    MEDIUM_LEVEL  = 2,
    EXTREME_LEVEL = 3
} levelDifficulty;

levelDifficulty getDifficultyFromInput(const size_t input);
void setDifficultyFromInput(levelDifficulty* level, const size_t input);

size_t getW(levelDifficulty level);
size_t getH(levelDifficulty level);
size_t getM(levelDifficulty level);

#endif