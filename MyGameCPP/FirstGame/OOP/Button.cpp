#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Button.h"

Button::Button(Vec2 position, string ButtonOffTrigger, SDL_Renderer* ButtonRenderer)
    :ButtonRenderer(ButtonRenderer), ButtonOffTrigger(ButtonOffTrigger)
{
    ButtonTexture = IMG_LoadTexture(ButtonRenderer, ButtonOffTrigger.c_str());

    int width, height;
    SDL_QueryTexture(ButtonTexture, nullptr, nullptr, &width, &height);
    
    destinationRect.x = static_cast<int>(position.x);
	destinationRect.y = static_cast<int>(position.y);
    destinationRect.h = 100;
    destinationRect.w = 300;
    
    sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = width;
	sourceRect.h = height;
}

Button::~Button()
{
    SDL_DestroyTexture(ButtonTexture);
}

void Button::Update(Mouse& mouse, string ButtonOnTrigger)
{
    if(SDL_HasIntersection(&destinationRect, &mouse.MousePointer))
    {
        isSelected = true;
        ButtonTexture = IMG_LoadTexture(ButtonRenderer, ButtonOnTrigger.c_str());
    }else{
        isSelected = false;
        ButtonTexture = IMG_LoadTexture(ButtonRenderer, ButtonOffTrigger.c_str());
    }
}

void Button::Draw()
{
    SDL_RenderCopy(ButtonRenderer, ButtonTexture, &sourceRect, &destinationRect);
}

