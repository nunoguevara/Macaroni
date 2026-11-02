cmake_minimum_required(VERSION 3.31)
project(Macaroni LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(macaroni main.c)

install(TARGETS macaroni DESTINATION bin)
