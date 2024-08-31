#ifndef MYSDLAPP_HPP
#define MYSDLAPP_HPP
#include <SDL2/SDL.h>
// Your header file content goes here

class drawRect {
    public:
        static void DrawFilledRect(SDL_Renderer* m_window_renderer, int x, int y, int width, int height, SDL_Color color);
};

#endif // MYSDLAPP_HPP
