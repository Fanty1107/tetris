cmake_minimum_required(VERSION 3.16) 
project(tetris LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

find_package(raylib REQUIRED CONFIG)

add_executable(tetris src/main.cpp src/borders.cpp) 
target_include_directories(tetris PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(tetris PRIVATE raylib)
