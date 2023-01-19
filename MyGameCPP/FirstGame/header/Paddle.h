#include <iostream>
#include <SDL2/SDL.h>
#include "Vec2.h"

#ifndef Paddle_H
#define Paddle_H

const int PADDLE_WIDTH = 5, PADDLE_HEIGHT = 100;
extern const int WINDOW_HEIGHT, WINDOW_WIDTH;

class Paddle
{
private :
   SDL_Rect PaddleRect{};
public:
   Vec2 position; 
   Vec2 velocity;

   Paddle(Vec2 position, Vec2 velocity);

   void PaddleUpdate(float dt);

   void Draw(SDL_Renderer* renderer);
};

#endif