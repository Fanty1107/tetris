#include "game.hpp"
#include <raylib.h>
#include <vector>

int main() {
    //init game obj
	Window win = Window(660, 900, "Tetris");
	Borders borders = Borders(&win);
      std::vector<Piece> pieces;
      Game tetris = Game(&win, &borders, &pieces);
//      pieces.push_back(Piece(tetris.get_random_type()));

	while (!WindowShouldClose()) {
          //Game loop
		float dt = GetFrameTime();
		BeginDrawing();
		ClearBackground(BLACK);
		borders.draw();
            tetris.check_collision();
            tetris.spawn_pieces();
            for (auto& piece : pieces) {
                piece.update_pos(dt, &win);
                piece.draw_blocks();
            }
		win.draw_grid();
		EndDrawing();
	}
	return 0;
}
