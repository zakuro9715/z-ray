cmake_minimum_required(VERSION 3.5)

project(z-ray C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FindOpenMP)
if(OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()

add_executable(
    z-ray src/main.c
    src/math_utils.c
    src/image.c 
    src/object.c
    src/random.c   
    src/render.c
    src/scene.c
    src/vec.c
)

add_definitions("-std=c11 -Wall -pedantic-errors")
target_link_libraries(z-ray m)
