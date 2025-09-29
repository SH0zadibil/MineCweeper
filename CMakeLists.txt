cmake_minimum_required(VERSION 3.10)
project(MineCweeper C)

# Add all subdirectories (folders) containing source/header files
# Replace 'src', 'include', etc. with your actual folder names if different
add_subdirectory(src)
add_subdirectory(include)

# Collect all source files (including main.c)
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.c"
    "${CMAKE_SOURCE_DIR}/main.c"
)

# Add executable target
add_executable(MineCweeper ${SOURCES})

# Include directories for header files
target_include_directories(MineCweeper PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

# Link libraries if needed (uncomment and modify if you have any)
# target_link_libraries(MineCweeper some_library)