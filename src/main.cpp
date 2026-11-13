#include "../include/window.hpp"
#include "../include/borders.hpp"
#include "../include/blocks.hpp"

int main(){
    Window w = Window(650,900,"Tetris");
    Borders borders = Borders(&w); 
    Piece p = Piece(Types::L);

    while(!WindowShouldClose()){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        borders.draw();
        p.draw_blocks();
    EndDrawing();
    }
    return 0;
}
