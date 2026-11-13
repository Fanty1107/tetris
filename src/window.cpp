#include <raylib.h>
#include "../include/window.hpp"

Window::Window(int w, int h, const char *t){
    width = w, height = h, title = t;
    InitWindow(width, height, title);
}
Window::~Window(){
    CloseWindow();
}
