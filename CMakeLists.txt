cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET src/.c/main.c src/.c/fonction_allegro.c src/.h/fonction_allegro.h src/.c/fonction_allegro.c src/.h/fonction_allegro.h src/.c/fonction_project.c src/.h/fonction_project.h src/.c/fonction_utile.c src/.h/fonction_utile.h "src/.c/fonction game snake.c" "src/.h/fonction game snake.h" "src/.c/fonction game fighter.c" "src/.h/fonction game fighter.h")

target_link_libraries(PROJET -lmingw32 -lalleg44)
