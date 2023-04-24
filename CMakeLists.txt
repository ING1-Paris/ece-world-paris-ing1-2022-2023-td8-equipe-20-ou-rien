cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET src/main.c src/fonction_allegro.c src/fonction_allegro.h src/fonction_allegro.c src/fonction_allegro.h)

target_link_libraries(PROJET -lmingw32 -lalleg44)
