#include "pieces.hpp"
Piece::Piece() {}
Piece::Piece(Types::Piece tp) {
	speed	= 200.0f;
    #ifdef DEBUG // check the header file for this flag 
    speed = 800.0f;
    #endif
	type	= tp;
      isDown = false;
      spawn_more = false;
	float x = rand_on_grid();
	float y = 90.0f; // float is the same for init
	switch (type) {
	case Types::I: {
		for (int i = 0; i < 4; i++) {
			blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
			x += BLOCK_SIZE;
		}
		break;
	}
	case Types::L: {
		for (int i = 0; i < 4; i++) {
			if (i == 3) {
				x += BLOCK_SIZE;
				y -= BLOCK_SIZE;
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
			} else {
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				y += BLOCK_SIZE;
			}
		}
		break;
	}
	case Types::J: {
		for (int i = 0; i < 4; i++) {
			if (i == 3) {
				x -= BLOCK_SIZE;
				y -= BLOCK_SIZE;
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
			} else {
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				y += BLOCK_SIZE;
			}
		}
		break;
	}
	case Types::O: {
		for (int i = 0; i < 4; i++) {
			switch (i) {
			case 0:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				y += BLOCK_SIZE;
				break;
			case 1:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				x -= BLOCK_SIZE;
				break;
			case 2:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				y -= BLOCK_SIZE;
				break;
			case 3:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				break;
			}
		}
		break;
	}
	case Types::S:{
                for(int i = 0; i < 4; i++){
                switch (i) {
			case 0:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				x -= BLOCK_SIZE;
				break;
			case 1:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				y += BLOCK_SIZE;
				break;
			case 2:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				x -= BLOCK_SIZE;
				break;
			case 3:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				break;
			}
                }
		break;
            }
	case Types::T:{
                for(int i = 0; i < 4; i++){
                switch (i) {
			case 0:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				x += BLOCK_SIZE;
				break;
			case 1:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				y -= BLOCK_SIZE;
				break;
			case 2:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
                        y += BLOCK_SIZE;
				x += BLOCK_SIZE;
				break;
			case 3:
				blocks[i] = {x, y, BLOCK_SIZE, BLOCK_SIZE};
				break;
			}
		break;
            }
	case Types::Z:
		break;
	}
    }
}
float Piece::rand_on_grid() {
	// 660 window width
	// all numbers in grid x go with, x += BLOCK_SIZE;
	int cols = 550 / BLOCK_SIZE;
	float x	 = GetRandomValue(0, cols - 1) * BLOCK_SIZE;
	return x;
}
void Piece::update_pos(float dt, Window *w) {
	for (int i = 0; i < 4; i++) {
		if (blocks[i].y > (float)w->height - (BLOCK_SIZE * 2)) {
                  isDown = true;  
			speed = 0;
		}
		blocks[i].y += dt * speed;
	}
}
void Piece::move_piece(float dt, Window *w){
    if(IsKeyPressed(KEY_D) && !isDown){
        for(auto& block : blocks)
        {
            block.x += BLOCK_SIZE;    
        } 
    }
    if(IsKeyPressed(KEY_A) && !isDown){
        for(auto& block : blocks)
        {
            block.x -= BLOCK_SIZE;    
        } 
    }
}
void Piece::draw_blocks() {
	for (int i = 0; i < 4; i++) {
		DrawRectangleRec(blocks[i], GREEN);
	}
}
