cmake_minimum_required(VERSION 3.24)
project(tetris LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.2
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS 6.2 CONFIG 
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

add_executable(tetris src/main.cpp src/borders.cpp src/window.cpp src/pieces.cpp src/game.cpp)
target_include_directories(tetris PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(tetris PRIVATE raylib)
