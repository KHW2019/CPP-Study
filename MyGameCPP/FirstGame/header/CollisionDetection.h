#include <iostream>
#include <SDL2/SDL.h>
#include "Paddle.h"
#include "Ball.h"
#include "GameManager.h"

#ifndef CollisionDetection_H
#define CollisionDetection_H

class CollisionDetection
{
private:
    GameManager GM;
public:

    // enum class CollisionType
    // {
    //     None,
    //     Top,
    //     Middle, 
    //     Bottom
    // };

    // struct Contact
    // {
    //     CollisionType type;
    //     float penetration;
    // };
    
    // void CollideWithPaddle(Contact const& contact, Ball ball);

    Ball::Contact checkPaddleCollision(Ball const& ball, Paddle const& paddle);

    Ball::Contact CheckWallCollision(Ball const& ball);

    
};

#endif