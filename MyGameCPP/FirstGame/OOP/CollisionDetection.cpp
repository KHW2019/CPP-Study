#include <iostream>
#include <SDL2/SDL.h>
#include "CollisionDetection.h"
#include "Ball.h"

// void CollisionDetection::CollideWithPaddle(Contact const& contact, Ball ball)
// {
//     ball.position.x += contact.penetration;
//     ball.velocity.x = -ball.velocity.x;

//     if(contact.type == CollisionType::Top)
//     {
//         ball.velocity.y = -0.75f * BALL_SPEED;
//     }else if(contact.type == CollisionType::Bottom)
//     {
//         ball.velocity.y = 0.75f * BALL_SPEED;
//     }
// } 

Ball::Contact CollisionDetection::checkPaddleCollision(Ball const& ball, Paddle const& paddle)
{
    float ballLeft = ball.position.x;
    float ballRight = ball.position.x + BALL_WIDTH;
    float ballTop = ball.position.y;
    float ballBottom = ball.position.y + BALL_HEIGHT;

    float paddleLeft = paddle.position.x;
    float paddleRight = paddle.position.x + PADDLE_WIDTH;
    float paddleTop = paddle.position.y;
    float paddleBottom = paddle.position.y + PADDLE_HEIGHT;

    Ball::Contact contact{};

    if(ballLeft >= paddleRight)
    {
        return contact;
    }

    if(ballRight <= paddleLeft)
    {
        return contact;
    }

    if(ballTop >= paddleBottom)
    {
        return contact;
    }

    if(ballBottom <= paddleTop)
    {
        return contact;
    }

    float paddleRangerUpper = paddleBottom - (2.0f * PADDLE_HEIGHT / 3.0f);
    float paddleRangerMiddle = paddleBottom - (PADDLE_HEIGHT / 3.0f);

    if(ball.velocity.x < 0)
    {
        contact.penetration = paddleRight - ballLeft;
    }
    else if(ball.velocity.x > 0)
    {
        contact.penetration = paddleLeft - ballRight;
    }

    if((ballBottom > paddleTop) && (ballBottom < paddleRangerUpper))
    {
        contact.type = Ball::CollisionType::Top;
    }
    else if((ballBottom > paddleRangerUpper) && (ballBottom < paddleRangerMiddle))
    {
        contact.type  = Ball::CollisionType::Middle;
    }
    else
    {
        contact.type = Ball::CollisionType::Bottom;
    }

    return contact;
}

Ball::Contact CollisionDetection::CheckWallCollision(Ball const& ball)
{
    float ballLeft = ball.position.x;
    float ballRight = ball.position.x + BALL_WIDTH;
    float ballTop = ball.position.y;
    float ballBottom = ball.position.y + BALL_HEIGHT;

    Ball::Contact contact{};

    if(ballLeft < 0.0f)
    {
        contact.type = Ball::CollisionType::left;
    }
    else if(ballRight > WINDOW_WIDTH)
    {
        contact.type = Ball::CollisionType::right;
    }
    else if(ballTop < 0.0f)
    {
        contact.type = Ball::CollisionType::Top;
    }
    else if(ballBottom > WINDOW_HEIGHT)
    {
        contact.type = Ball::CollisionType::Bottom;
    }
    
    return contact;
}
