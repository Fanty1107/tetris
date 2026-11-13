#include "../include/borders.hpp"
#include "../include/blocks.hpp"

Borders::Borders(Window *w){
    top    = {.x = 0.0f, .y = 0.0f,                   .width = STC_CAST(float, w->width), .height = BLOCK_SIZE};
    bottom = {.x = 0.0f, .y = STC_CAST(float, w->height) - BLOCK_SIZE, .width = STC_CAST(float , w->width), .height = BLOCK_SIZE};
    left   = {.x = 0.0f, .y = BLOCK_SIZE,                  .width = BLOCK_SIZE,          .height = STC_CAST(float, w->height)};
    right  = {.x = STC_CAST(float, w->width) - BLOCK_SIZE, .y = 0.0f,.width = BLOCK_SIZE, .height = STC_CAST(float, w->height)};
}
void Borders::draw(){
    DrawRectangleRec(top, RED);
    DrawRectangleRec(bottom, RED);
    DrawRectangleRec(left, RED);
    DrawRectangleRec(right, RED);
}
