#include "game.hpp"
#include <cstddef>

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
    for (size_t i = 0; i < pic->size(); ++i) {
        for (size_t j = i + 1; j < pic->size(); ++j) {
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
                pic->at(j).isDown = true;
            }
        }
    }
}

Types::Piece Game::get_random_type(){
    int idx = GetRandomValue(0, 6);
    switch (idx) {
        case 0: return Types::I;
            break;
        case 1: return Types::J;
            break;
        case 2: return Types::L;
            break;
        case 3: return Types::O;
            break;
        case 4: return Types::S;
            break;
//      case 5: return Types::T;
//          break;
//      case 6: return Types::Z;
//          break;
        default: return Types::I;
            break;
    }
}
void Game::spawn_pieces(){
    if(pic->empty()){
        pic->push_back(Piece(get_random_type())); 
        return;
    }
    for(std::size_t i = 0; i < pic->size(); ++i){
        if(pic->at(i).isDown && !pic->at(i).spawn_more){
           pic->at(i).spawn_more = true;
           pic->push_back(Piece(get_random_type())); 
           return;
        } 
    }  
}
void Game::get_user_input(float dt){
    if(pic->empty()){
        return;
    }
    for(auto& piece : *pic){
       piece.move_piece(dt, win); 
    }
}
bool Game::check_destroy_line(std::vector<Rectangle>& colliders){
    const int rows = win->height / BLOCK_SIZE;
    const int cols = win->width / BLOCK_SIZE;
    for(int row = rows - 1; row >= 0; --row){
        int filled = 0;
        float lineY = row * BLOCK_SIZE;
        for (const Piece& piece : *pic) {
            if (!piece.isDown) continue;

            for (const Rectangle& block : piece.blocks) {
                if (block.y == lineY) {
                    ++filled;
                }
            }
        }
        if(filled != cols) continue;

        for(Piece& piece : *pic){
            if(!piece.isDown) continue;
            for(Rectangle& block : piece.blocks){
                if(block.y == lineY){
                    block.width = 0;
                    block.height = 0;
                }else if(block.y < lineY){
                    block.y += BLOCK_SIZE;
                }
            }
        }
        return true;
    }
    return false;
}
