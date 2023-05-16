cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET src/.c/main.c src/.c/fonction_allegro.c src/.c/fonction_project.c src/.c/fonction_utile.c src/.c/fonction_game_snake.c src/.c/fonction_game_fighter.c  src/.c/display.c src/.c/free.c src/.c/game.c src/.c/gun.c src/.c/handleError.c src/.c/loadMap.c src/.c/fonction_labyrith.c src/.c/opps.c src/.c/pauseMenu.c src/.c/player.c src/.c/quickSort.c src/.c/raycasting.c src/.h/header.h src/.c/fonction_riviere.c src/.h/fonction_riviere.h jadou/Marp.c jadou/sous.c)

target_link_libraries(PROJET -lmingw32 -lalleg44 -lm -lwinmm)