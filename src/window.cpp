#include "../include/window.hpp"
#include "../include/blocks.hpp"

Window::Window(int w, int h, const char *t){
    width = w, height = h, title = t;
    InitWindow(width, height, title);
}
Window::~Window(){
    CloseWindow();
}
void Window::draw_grid(){
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
