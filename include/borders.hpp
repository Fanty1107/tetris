#ifndef BORDERS_H
#define BORDERS_H

#include "window.hpp"
#include <raylib.h>

#define STC_CAST(t, arg) static_cast<t>((arg))

struct Borders{
    Borders(Window *w);
    Rectangle top;
    Rectangle bottom;
    Rectangle left;
    Rectangle right;
    void draw();
};
#endif
