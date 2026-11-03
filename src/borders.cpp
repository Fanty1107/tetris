#include "../include/borders.hpp"

Borders::Borders(){
    top    = {.x = 0.0f, .y = 0.0f,                   .width = (float)W_WIDTH, .height = 50.0f};
    bottom = {.x = 0.0f, .y = (float)W_HEIGHT - 50.0f, .width = (float)W_WIDTH, .height = 50.0f};
    left   = {.x = 0.0f, .y = 50.0f,                  .width = 50.0f,          .height = (float)W_HEIGHT};
    right  = {.x = 550.0f, .y = 0.0f,                  .width = 50.0f,          .height = (float)W_HEIGHT};
}
void Borders::draw(){
    DrawRectangleRec(top, RED);
    DrawRectangleRec(bottom, RED);
    DrawRectangleRec(left, RED);
    DrawRectangleRec(right, RED);
}
