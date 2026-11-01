#include "../include/borders.h"

int main(){
    InitWindow(W_WIDTH, W_HEIGHT, TITLE);
    Borders bors = initBorders();

    while(!WindowShouldClose()){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_borders(&bors);
    EndDrawing();
    }
    CloseWindow();
    return 0;
}
