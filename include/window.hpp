#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <raylib.h>

struct Window{
    int width;
    int height;
    const char *title; 
    std::vector<Rectangle> make_col_grid();
    void draw_grid();
    void draw_col_grid(std::vector<Rectangle>&);
    Window(int w, int h, const char *t);
    ~Window();
};
#endif
