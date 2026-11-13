#include "../include/window.hpp"
#include "../include/borders.hpp"
#include "../include/blocks.hpp"

int main(){
    Window w = Window(660,900,"Tetris");
    Borders borders = Borders(&w); 
    Piece p = Piece(Types::L);
    Piece p2 = Piece(Types::I);

    while(!WindowShouldClose()){
    float dt = GetFrameTime();
    p.update_pos(dt, &w);
    p2.update_pos(dt, &w);
    BeginDrawing();
        ClearBackground(BLACK);
        borders.draw();
        p.draw_blocks();
        p2.draw_blocks();
        w.draw_grid();
    EndDrawing();
    }
    return 0;
}
