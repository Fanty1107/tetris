#include "../include/window.hpp"
#include "../include/borders.hpp"

int main(){
    Window w = Window(600,900,"Tetris");
    Borders borders = Borders(&w); 

    while(!WindowShouldClose()){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        borders.draw();
    EndDrawing();
    }
    return 0;
}
