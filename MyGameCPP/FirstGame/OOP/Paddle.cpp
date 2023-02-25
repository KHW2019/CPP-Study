#include <iostream>
#include <SDL2/SDL.h>
#include "Paddle.h"

using namespace std;

Paddle::Paddle(Vec2 position, Vec2 velocity)
	: position(position), velocity(velocity)
{
	PaddleRect.x = static_cast<int>(position.x);
	PaddleRect.y = static_cast<int>(position.y);
	PaddleRect.w = PADDLE_WIDTH;
	PaddleRect.h = PADDLE_HEIGHT;
}

void Paddle::PaddleUpdate(float dt)
{
	position += velocity * dt;

	if(position.y < 0){
		position.y = 0;
	}
	else if(position.y > (GM.WINDOW_HEIGHT - PADDLE_HEIGHT))
	{
		position.y = GM.WINDOW_HEIGHT - PADDLE_HEIGHT;
	}
}

void Paddle::Draw(SDL_Renderer *renderer)
{
	PaddleRect.y = static_cast<int>(position.y);

	SDL_RenderFillRect(renderer, &PaddleRect);
}


