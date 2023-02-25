#include <iostream>
#include <SDL2/SDL.h>
#include "Vec2.h"
#include "GameManager.h"

#ifndef Ball_H
#define Ball_H

class Ball{
private:
    
    GameManager GM;

public:
    const int BALL_WIDTH = 15, BALL_HEIGHT = 15;
    Vec2 position;
    Vec2 velocity;
    SDL_Rect BallRect{};

    enum class CollisionType
    {
        None,
        Top,
        Middle, 
        Bottom, 
        left,
        right
    };

    struct Contact
    {
        CollisionType type;
        float penetration;
    };

    Ball(Vec2 position, Vec2 velocity);

    void CollideWithPaddle(Contact const& contact);

    void CollideWithWall(Contact const& contact);

    void BallUpdate(float dt);

    void Draw(SDL_Renderer* renderer);
    
};

#endif