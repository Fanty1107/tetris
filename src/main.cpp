#include "game.hpp"

int main() {
    //init game obj
	Window win = Window(660, 900, "Tetris");
	Borders borders = Borders(&win);
      std::vector<Piece> pieces;
      Game tetris = Game(&win, &borders, &pieces);
      std::vector<Rectangle> colliders = win.make_col_grid();

	while (!WindowShouldClose()) {
          //Game loop
		float dt = GetFrameTime();
		BeginDrawing();
		ClearBackground(BLACK);
            tetris.get_user_input(dt);
            tetris.check_destroy_line(colliders);
		borders.draw();
            tetris.check_collision();
            tetris.spawn_pieces();
            for (auto& piece : pieces) {
                piece.update_pos(dt, &win);
                piece.draw_blocks();
            }
            win.draw_col_grid(colliders);
		//win.draw_grid();
		EndDrawing();
	}
	return 0;
}
