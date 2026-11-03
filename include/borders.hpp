#ifndef BORDERS_H
#define BORDERS_H

#include <raylib.h>
#define W_WIDTH 600
#define W_HEIGHT 900
#define TITLE "Tetris"

struct Borders{
    Borders();
    Rectangle top;
    Rectangle bottom;
    Rectangle left;
    Rectangle right;
    void draw();
};
#endif
