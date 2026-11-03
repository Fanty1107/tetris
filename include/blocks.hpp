#ifndef BLOCKS_H
#define BLOCKS_H

#include "../include/borders.hpp"
#include <vector>

constexpr int BLOCK_SIZE = 40;

struct Piece{
    Piece();
    Rectangle blocks[4];
    std::vector<Rectangle[4]> piece;
    void draw();
    void update_pos();
    void check_collision();
};

#endif//BLOCKS_H
