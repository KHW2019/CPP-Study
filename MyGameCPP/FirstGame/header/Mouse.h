#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Vec2.h"

#ifndef MOUSE_H
#define MOUSE_H

class Mouse
{
private:
    SDL_Rect MouseRect;
    SDL_Renderer* MouseRenderer;

public:

    SDL_Rect MousePointer;
    SDL_Texture* MouseTexture;

    Mouse(SDL_Renderer* renderer);    

    void Update();
    
    void Draw();
};

#endif