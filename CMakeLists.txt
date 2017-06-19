cmake_minimum_required(VERSION 3.5)

project(z-ray C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
    z-ray src/main.c
    src/math_utils.c
    src/image.c 
    src/random.c   
    src/vec.c
)

add_definitions("-std=c11 -Wall -pedantic-errors")
target_link_libraries(z-ray m)
