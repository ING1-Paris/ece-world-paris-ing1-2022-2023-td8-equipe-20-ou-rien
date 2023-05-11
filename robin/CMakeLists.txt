cmake_minimum_required(VERSION 3.23)
project(PROJETS2 C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJETS2 main.c)

target_link_libraries(PROJETS2 -lmingw32 -lalleg44)