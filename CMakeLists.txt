cmake_minimum_required(VERSION 3.10)
project(MineCweeper C)

file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.c"
    "${CMAKE_SOURCE_DIR}/main.c"
)

add_executable(MineCweeper ${SOURCES})

target_include_directories(MineCweeper PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/include/game"
)