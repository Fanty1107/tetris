#include "../include/blocks.hpp"
#include "../include/borders.hpp"
#include "../include/window.hpp"

int main() {
	Window w	    = Window(660, 900, "Tetris");
	Borders borders = Borders(&w);
	Piece p	    = Piece(Types::J);
	Piece p2	    = Piece(Types::O);

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		p.update_pos(dt, &w);
		p2.update_pos(dt, &w);

		BeginDrawing();
		ClearBackground(BLACK);
		borders.draw();
		p.draw_blocks();
		p2.draw_blocks();
		w.draw_grid();
		EndDrawing();
	}
	return 0;
}
