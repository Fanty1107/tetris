#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include "pieces.hpp"
#include "borders.hpp"
#include "window.hpp"


struct Game{
    Window *win;
    Borders *bor;
    std::vector<Piece> *pic;

    Game();
    Game(Window *w, Borders *b, std::vector<Piece> *p);
    Types::Piece get_random_type();
    void spawn_pieces();
    void check_collision();
};

#endif//GAME_HPP
