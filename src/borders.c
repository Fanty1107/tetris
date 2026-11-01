#include "../include/borders.h"

Borders initBorders(){
    Borders bors;
    Rectangle top = {.x=0.0f,.y=0.0f, (float)W_WIDTH, 50.0f};
    Rectangle bottom = {.x=0.0f, .y=(float)W_HEIGHT - 50.0f, (float)W_WIDTH, 50.0f};
    Rectangle left = {.x=0.0f, .y=50.0f, 50.0f, (float)W_HEIGHT};
    Rectangle right = {.x = 550.0f,.y=0.0f, 50.0f, (float)W_HEIGHT };

    bors.top = top;
    bors.bottom = bottom;
    bors.left = left;
    bors.right = right;
    return bors;
}
void draw_borders(Borders *b){
    DrawRectangleRec(b->top, RED);
    DrawRectangleRec(b->bottom, RED);
    DrawRectangleRec(b->left, RED);
    DrawRectangleRec(b->right, RED);
}

