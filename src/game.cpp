#include "../include/game.hpp"

Game::Game(Window *w, Borders *b, std::vector<Piece> *p){
    win = w;
    bor = b;
    pic = p;
}

void Game::check_collision()
{
    if (pic == nullptr) {
        return;
    }

    // Compara cada par apenas uma vez.
    for (std::size_t i = 0; i < pic->size(); ++i) {
        for (std::size_t j = i + 1; j < pic->size(); ++j) {
            bool collided = false;

            for (const Rectangle& blockA : (*pic)[i].blocks) {
                for (const Rectangle& blockB : (*pic)[j].blocks) {
                    if (CheckCollisionRecs(blockA, blockB)) {
                        collided = true;
                        break;
                    }
                }
                if (collided) {
                    break;
                }
            }
            if (collided) {
                pic->at(j).speed = 0;
            }
        }
    }
}
