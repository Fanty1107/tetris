#include "../include/borders.hpp"

int main(){
    InitWindow(W_WIDTH, W_HEIGHT, TITLE);
    Borders borders; 

    while(!WindowShouldClose()){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        borders.draw();
    EndDrawing();
    }
    CloseWindow();
    return 0;
}
