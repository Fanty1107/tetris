#include "../include/blocks.hpp"
#include <raylib.h>

//Window is 650x900 all borders are 50px
//600x850 for the actual game
//each piece is 30
//top = {.x = 0.0f, .y = 0.0f, .width = STC_CAST(float, w->width), .height = BLOCK_SIZE};
Piece::Piece(){}
Piece::Piece(Types::Piece tp){
    type = tp;
    speed = 200.0f;
    float x = rand_on_grid();
    float y = 90.0f;//float is the same for init
    switch (type) {
        case Types::I:{
                for(int i = 0; i < 4; i++){
                    blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
                    x += BLOCK_SIZE;
                }
            break;
            }
        case Types::L:{
                for(int i = 0; i < 4; i++){
                    if(i == 3){
                        x += BLOCK_SIZE;
                        y -= BLOCK_SIZE;
                        blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
                    }else{
                        blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
                        y += BLOCK_SIZE;
                    }
                }
            break;
            }
        case Types::J:
            break;
        case Types::O:
            break;
        case Types::S:
            break;
        case Types::T:
            break;
        case Types::Z:
            break;
    }
}
float Piece::rand_on_grid(){
    //660 window width
    //all numbers in grid x go with, x += BLOCK_SIZE;
    int cols = 600 / BLOCK_SIZE;               
    float x = GetRandomValue(0, cols - 1) * BLOCK_SIZE;
    return x;
}
void Piece::draw(){}
void Piece::update_pos(float dt, Window *w){
    for(int i = 0; i < 4; i++){
        if(blocks[i].y > w->height - (BLOCK_SIZE * 2)){
            speed = 0;
        }
        blocks[i].y += dt * speed;
    }
}
void Piece::check_collision(){}
void Piece::draw_blocks(){
    for(int i = 0; i < 4; i++){
        DrawRectangleRec(blocks[i], GREEN);
    }
}
