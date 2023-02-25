#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Mouse.h"
#include "Vec2.h"

using namespace std;

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
private:
    SDL_Texture* ButtonTexture;
    SDL_Renderer* ButtonRenderer;
    SDL_Rect sourceRect, destinationRect;
    
    string ButtonOnTrigger;
    string ButtonOffTrigger;

public:

    bool isSelected = false;

    Button(Vec2 position, string ButtonOffTrigger, SDL_Renderer* ButtonRenderer);

    virtual ~Button();

    void Update(Mouse&, string ButtonOnTrigger);

    void Draw();
};

#endif