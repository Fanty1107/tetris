#include "../include/pieces.hpp"
#include "../include/borders.hpp"
#include "../include/window.hpp"
#include <vector>

int main() {
	Window w	    = Window(660, 900, "Tetris");
	Borders borders = Borders(&w);
      std::vector<Piece> pieces;
      pieces.push_back(Piece(Types::I));
      pieces.push_back(Piece(Types::O));

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		BeginDrawing();
		ClearBackground(BLACK);
		borders.draw();
            for (auto& piece : pieces) {
                piece.update_pos(dt, &w);
                piece.draw_blocks();
            }
		w.draw_grid();
		EndDrawing();
	}
	return 0;
}
