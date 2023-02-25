#include <iostream>
#include <SDL2/SDL.h>
#include "Vec2.h"
#include "GameManager.h"

#ifndef Paddle_H
#define Paddle_H

const int PADDLE_WIDTH = 5, PADDLE_HEIGHT = 100;

class Paddle
{
private :
   SDL_Rect PaddleRect{};
   GameManager GM;
public:
   Vec2 position; 
   Vec2 velocity;

   const float PADDLE_SPEED = 1.0f;

   Paddle(Vec2 position, Vec2 velocity);

   void PaddleUpdate(float dt);

   void Draw(SDL_Renderer* renderer);
};

#endif