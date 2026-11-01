#ifndef BORDERS_H
#define BORDERS_H

#include <raylib.h>
#define W_WIDTH 600
#define W_HEIGHT 900
#define TITLE "Tetris"

typedef struct{
    Rectangle top;
    Rectangle bottom;
    Rectangle left;
    Rectangle right;
}Borders;
Borders initBorders();
void draw_borders(Borders *b);
#endif
