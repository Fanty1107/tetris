#include "pieces.hpp"
#include "window.hpp"

Window::Window(int w, int h, const char *t) {
	width = w, height = h, title = t;
	InitWindow(width, height, title);
}
Window::~Window() { CloseWindow(); }
void Window::draw_grid() {
	int x = 0;
	while (x <= width) {
		DrawLine(x, 0, x, height, RAYWHITE);
		x += BLOCK_SIZE;
	}
	int y = 0;
	while (y <= height) {
		DrawLine(0, y, width, y, RAYWHITE);
		y += BLOCK_SIZE;
	}
}
//draw_line(start_pos_x, start_pos_y, end_pos_x, end_pos_y, color)
std::vector<Rectangle> Window::make_col_grid(){
    std::vector<Rectangle> line_collid;
    for (float y = 0.0f; y < height; y += BLOCK_SIZE) {
    for (float x = 0.0f; x < width; x += BLOCK_SIZE) {
        Rectangle rec{
            .x = x,
            .y = y,
            .width = static_cast<float>(BLOCK_SIZE),
            .height = static_cast<float>(BLOCK_SIZE)
        };
        line_collid.push_back(rec);
        }
    }
    return line_collid;
}

void Window::draw_col_grid(std::vector<Rectangle>& colliders){
    for(const auto& rect : colliders){
        DrawRectangleLinesEx(rect, 1.0f, BLUE);
    }
}
