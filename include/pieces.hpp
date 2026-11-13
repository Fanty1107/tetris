#ifndef BLOCKS_H
#define BLOCKS_H

#include "window.hpp"
#include <raylib.h>

constexpr float BLOCK_SIZE = 30;

namespace Types{
    enum Piece{
        I = 0xF00,
        J = 0x44C0,
        L = 0x4460,
        O = 0xCC00,
        S = 0x6C0,
        T = 0xE40,
        Z = 0xC60,
    };
}

struct Piece{
    Piece();
    Piece(Types::Piece tp);
    Rectangle blocks[4];
    Types::Piece type;
    float speed;

    void draw();
    void draw_blocks();
    float rand_on_grid();
    void update_pos(float dt, Window *w);
    void check_collision();
};

#endif//BLOCKS_H
