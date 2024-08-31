#include <SDL2/SDL.h>
#include "drawRect.hpp"
#include <iostream>

void drawRect::DrawFilledRect(SDL_Renderer* m_window_renderer, int x, int y, int width, int height, SDL_Color color) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_SetRenderDrawColor(m_window_renderer, color.r, color.b, color.g, color.a);
    SDL_RenderDrawRect(m_window_renderer, &rect);
    SDL_RenderFillRect(m_window_renderer, &rect);
    SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 0, 255);

}