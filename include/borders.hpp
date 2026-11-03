#ifndef BORDERS_H
#define BORDERS_H

#include <raylib.h>
constexpr const char* TITLE = "Tetris";
constexpr const int W_WIDTH = 600;
constexpr const int W_HEIGHT = 900;

struct Borders{
    Borders();
    Rectangle top;
    Rectangle bottom;
    Rectangle left;
    Rectangle right;
    void draw();
};
#endif
