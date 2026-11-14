#include "../include/game.hpp"
#include <raylib.h>
#include <vector>

Types::Piece get_random_type(){
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


int main() {
    //init game obj
	Window win = Window(660, 900, "Tetris");
	Borders borders = Borders(&win);
      std::vector<Piece> pieces;
      Game tetris = Game(&win, &borders, &pieces);
      pieces.push_back(Piece(get_random_type()));
      pieces.push_back(Piece(get_random_type()));

	while (!WindowShouldClose()) {
          //Game loop
		float dt = GetFrameTime();
		BeginDrawing();
		ClearBackground(BLACK);
		borders.draw();
            tetris.check_collision();
            for (auto& piece : pieces) {
                piece.update_pos(dt, &win);
                piece.draw_blocks();
            }
		win.draw_grid();
		EndDrawing();
	}
	return 0;
}
