#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Mouse.h"

using namespace std;

Mouse::Mouse(SDL_Renderer* renderer) 
    : MouseRenderer(renderer)
{
    MouseTexture = IMG_LoadTexture(MouseRenderer, "src/include/img/mouse2.png");
    
    MouseRect.w = 25;
    MouseRect.h = 25;
    
    MousePointer.w = 1;
    MousePointer.h = 1;

    SDL_ShowCursor(false);
}

void Mouse::Update()
{
    SDL_GetMouseState(&MouseRect.x , &MouseRect.y);
    MousePointer.x = MouseRect.x;
    MousePointer.y = MouseRect.y;
}

void Mouse::Draw()
{
    SDL_RenderCopy(MouseRenderer, MouseTexture, nullptr, &MouseRect);
}
