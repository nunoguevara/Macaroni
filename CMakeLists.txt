cmake_minimum_required(VERSION 3.31)
project(Pazt LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(ma src/macaroni.c)
add_executable(las src/lasagn.c)

install(TARGETS ma DESTINATION bin)
install(TARGETS las DESTINATION bin)
