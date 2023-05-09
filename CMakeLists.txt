cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET src/.c/main.c src/.c/fonction_game_fighter.c src/.c/fonction_allegro.c src/.c/fonction_project.c src/.c/fonction_utile.c src/.c/fonction_game_snake.c)

target_link_libraries(PROJET -lmingw32 -lalleg44)
