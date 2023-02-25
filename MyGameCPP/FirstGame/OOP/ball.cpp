#include <iostream>
#include <SDL2/SDL.h>
#include "Ball.h"

using namespace std;

Ball::Ball(Vec2 position, Vec2 velocity)
    : position(position), velocity(velocity)
{
    BallRect.x = static_cast<int>(position.x);
    BallRect.y = static_cast<int>(position.y);
    BallRect.w = BALL_WIDTH;
    BallRect.h = BALL_HEIGHT;
}

void Ball::CollideWithPaddle(Contact const& contact)
{
    position.x += contact.penetration;
    velocity.x = -velocity.x;

    if(contact.type == CollisionType::Top)
    {
        velocity.y = -0.75f * GM.BALL_SPEED;
    }else if(contact.type == CollisionType::Bottom)
    {
        velocity.y = 0.75f * GM.BALL_SPEED;
    }
} 

void Ball::CollideWithWall(Contact const& contact)
{
    if((contact.type == CollisionType::Top) 
        || (contact.type == CollisionType::Bottom))
    {
        position.y += contact.penetration;
        velocity.y = -velocity.y;
    }
    else if(contact.type == CollisionType::left)
    {
        position.x = GM.WINDOW_WIDTH / 2.0f;
        position.y = GM.WINDOW_HEIGHT / 2.0f;
        velocity.x = GM.BALL_SPEED;
        velocity.y = 0.75f * GM.BALL_SPEED;
    }
    else if(contact.type == CollisionType::right)
    {
        position.x = GM.WINDOW_WIDTH / 2.0f;
        position.y = GM.WINDOW_HEIGHT / 2.0f;
        velocity.x = -GM.BALL_SPEED;
        velocity.y = 0.75f* GM.BALL_SPEED;
    }
}

void Ball::BallUpdate(float dt)
{
    position += velocity * dt;
}

void Ball::Draw(SDL_Renderer *renderer)
{
    BallRect.x = static_cast<int>(position.x);
    BallRect.y = static_cast<int>(position.y);

    SDL_RenderFillRect(renderer, &BallRect);
}

