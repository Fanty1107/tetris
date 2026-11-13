#include "../include/borders.hpp"

Borders::Borders(Window *w){
    top    = {.x = 0.0f, .y = 0.0f,                   .width = STC_CAST(float, w->width), .height = 50.0f};
    bottom = {.x = 0.0f, .y = STC_CAST(float, w->height) - 50.0f, .width = STC_CAST(float , w->width), .height = 50.0f};
    left   = {.x = 0.0f, .y = 50.0f,                  .width = 50.0f,          .height = STC_CAST(float, w->height)};
    right  = {.x = STC_CAST(float, w->width) - 50.0f, .y = 0.0f,                  .width = 50.0f,          .height = STC_CAST(float, w->height)};
}
void Borders::draw(){
    DrawRectangleRec(top, RED);
    DrawRectangleRec(bottom, RED);
    DrawRectangleRec(left, RED);
    DrawRectangleRec(right, RED);
}
