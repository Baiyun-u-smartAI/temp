cmake_minimum_required(VERSION 3.19)
project(base64_1 C)

set(CMAKE_C_STANDARD 11)
set(${EXECUTABLE_OUTPUT_PATH} ${CMAKE_SOURCE_DIR})
add_executable(${PROJECT_NAME} main.c base64.h base64.c)
