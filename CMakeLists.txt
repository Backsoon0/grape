cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH ..)

project(Main LANGUAGES C)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_executable(Main ${SRC} main.c )