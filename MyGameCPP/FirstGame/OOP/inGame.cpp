#include "inGame.h"

using namespace std;

// void inGame::CreateTopBar()
// {
//     PlayerScore playerOneNameTag = PlayerScore(Vec2(0, 20),"PlayerOne : ", GM.renderer,GM.scoreFont);
//     PlayerScore playerOneScore = PlayerScore(Vec2(GM.WINDOW_WIDTH / 4.5 , 20),"0", GM.renderer, GM.scoreFont);
//     PlayerScore playerTwoNameTag = PlayerScore(Vec2(3 * GM.WINDOW_WIDTH / 4.5 , 20),"PlayerTwo :", GM.renderer,GM.scoreFont);
//     PlayerScore playerTwoScore = PlayerScore(Vec2(3 * GM.WINDOW_WIDTH / 3.4 , 20),"0", GM.renderer,GM.scoreFont);
// } 

// void inGame::DrawTopBar(SDL_Renderer* renderer)
// {
//     playerOneNameTag.Draw();
//     playerOneScore.Draw(renderer);
//     playerTwoNameTag.Draw(renderer);
//     playerTwoScore.Draw(renderer);
// }


void inGame::Draw(SDL_Renderer* renderer)
{

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    for (int y = 0; y < GM.WINDOW_HEIGHT; y++)
    {
        if (y % 5)
        {
            SDL_RenderDrawPoint(renderer, GM.WINDOW_WIDTH / 2, y);
        }
    }

    // playerOneNameTag.Draw(renderer);
    // playerOneScore.Draw(renderer);
    // playerTwoNameTag.Draw(renderer);
    // playerTwoScore.Draw(renderer);
    // DrawTopBar(renderer);

    ball.Draw(renderer);

    paddleOne.Draw(renderer);
    paddleTwo.Draw(renderer);
}

void inGame::Update(float dt)
{
    ball.BallUpdate(dt); 

    paddleOne.PaddleUpdate(dt);
    paddleTwo.PaddleUpdate(dt);
}

void inGame::CheckCollision()
{
    if (contact = cd.checkPaddleCollision(ball, paddleOne);
        contact.type != Ball::CollisionType::None)
    {
        ball.CollideWithPaddle(contact);

        Mix_PlayChannel(-1, GM.paddleHitSound, 0);
    }
    else if (contact = cd.checkPaddleCollision(ball, paddleTwo);
             contact.type != Ball::CollisionType::None)
    {
        ball.CollideWithPaddle(contact);

        Mix_PlayChannel(-1, GM.paddleHitSound, 0);
    }
    else if (contact = cd.CheckWallCollision(ball);
             contact.type != Ball::CollisionType::None)
    {
        ball.CollideWithWall(contact);
        if (contact.type == Ball::CollisionType::left)
        {
            ++PlayerTwoScore;

            playerTwoScore.SetScore(PlayerTwoScore);
        }
        else if (contact.type == Ball::CollisionType::right)
        {
            ++PlayerOneScore;

            playerOneScore.SetScore(PlayerOneScore);
        }
        else
        {
            Mix_PlayChannel(-1, GM.wallHitSound, 0);
        }
    }
}

void inGame::PlayerController()
{
    if (buttons[Buttons::PaddleOneUp])
    {
        paddleOne.velocity.y = -paddleOne.PADDLE_SPEED;
    }
    else if (buttons[Buttons::PaddleOneDown])
    {
        paddleOne.velocity.y = paddleOne.PADDLE_SPEED;
    }
    else
    {
        paddleOne.velocity.y = 0.0f;
    }

    if (buttons[Buttons::PaddleTwoUp])
    {
        paddleTwo.velocity.y = -paddleTwo.PADDLE_SPEED;
    }
    else if (buttons[Buttons::PaddleTwoDown])
    {
        paddleTwo.velocity.y = paddleTwo.PADDLE_SPEED;
    }
    else
    {
        paddleTwo.velocity.y = 0.0f;
    }
}