cmake_minimum_required(VERSION 3.10)
project(MineCweeper C)

set(CMAKE_C_STANDARD 17)

# Add include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/src/include/game
)

# List all source files
set(SOURCES
    main.c
    game.c
    src/difficulty.c
    src/level.c
)

add_executable(MineCweeper ${SOURCES})
