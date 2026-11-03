#ifndef BLOCKS_H
#define BLOCKS_H

#define BLOCK_SIZE 40

#include "../include/borders.hpp"
#include <vector>
struct Piece{
    Piece();
    Rectangle blocks[4];
    std::vector<Rectangle[4]> piece;
    void draw_pieces();
};

#endif//BLOCKS_H
