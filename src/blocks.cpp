#include "../include/blocks.hpp"
#include <raylib.h>

//Window is 650x900 all borders are 50px
//600x850 for the actual game
//each piece is 30
Piece::Piece(){
    float x = 90.0f;
    float y = 90.0f;
    Rectangle rec_b = {x, y, BLOCK_SIZE, BLOCK_SIZE};
    for(int i = 0; i < 4; i++){
        blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
        x += BLOCK_SIZE;
    }
}
Piece::Piece(Types::Piece tp){
    type = tp;
    float x = 90.0f;//TODO: make this number random in a window area
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
void Piece::draw(){}
void Piece::update_pos(){}
void Piece::check_collision(){}
void Piece::draw_blocks(){
    for(int i = 0; i < 4; i++){
        DrawRectangleLinesEx(blocks[i], 1.0f, GREEN);
    }
}
