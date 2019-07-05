cmake_minimum_required(VERSION 3.13)
project(test2)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES, main.cpp)
set(OpenCV_DIR "D:\\opencv_vs\\build") # 路径为自己下载的OpenCV路径
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(test2 main.cpp)
target_link_libraries(test2 ${OpenCV_LIBS})