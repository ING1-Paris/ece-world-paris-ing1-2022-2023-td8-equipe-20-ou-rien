cmake_minimum_required(VERSION 3.10)
project(myFps C)

set(CMAKE_C_STANDARD 99)

add_executable(myFps ./src/display.c ./src/free.c ./src/game.c ./src/gun.c ./src/handleError.c ./src/loadMap.c ./src/main.c ./src/opps.c ./src/pauseMenu.c ./src/player.c ./src/quickSort.c ./src/raycasting.c)

target_include_directories(myFps PRIVATE ./includes)

target_link_libraries(myFps -lmingw32 -lalleg44 -lm -lwinmm)