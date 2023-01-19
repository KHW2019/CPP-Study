#include <iostream>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Vec2.h"
#include "Ball.h"
#include "Paddle.h"
#include "PlayerScore.h"
#include "CollisionDetection.h"

using namespace std;

enum Buttons
{
    PaddleOneUp = 0,
    PaddleOneDown,
    PaddleTwoUp,
    PaddleTwoDown,
};

const int WINDOW_WIDTH = 1280, WINDOW_HEIGHT = 720;

int CenterLocation = SDL_WINDOWPOS_CENTERED;

const float PADDLE_SPEED = 1.0f;

CollisionDetection cd;
Ball::Contact contact;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); 
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    if(TTF_Init() == -1){
        cout<< "TTF INIT Error : " << TTF_GetError() << endl; 
        return 1;
    }
    
    SDL_Window* window = SDL_CreateWindow("Pong", CenterLocation, CenterLocation, WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    TTF_Font* scoreFont = TTF_OpenFont("src/include/dejavu-fonts-ttf/ttf/DejaVuSansMono.ttf", 40);

    Mix_Chunk* wallHitSound = Mix_LoadWAV("src/include/Sound/WallHit.wav");
    Mix_Chunk* paddleHitSound = Mix_LoadWAV("src/include/Sound/PaddleHit.wav");

    PlayerScore playerOneScoreText(Vec2(WINDOW_WIDTH / 4, 20), renderer,scoreFont);
    PlayerScore playerTwoScoreText(Vec2(3 * WINDOW_WIDTH / 4 , 20), renderer,scoreFont);

    Ball ball(
        Vec2(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT/ 2.0f), 
        Vec2(BALL_SPEED, 0.0f));
        
    Paddle paddleOne(Vec2(50.0f, WINDOW_HEIGHT / 2.0f), Vec2(0.0f, 0.0f));

    Paddle paddleTwo(Vec2(WINDOW_WIDTH - 50.0f, WINDOW_HEIGHT /2.0f), Vec2(0.0f, 0.0f));

    {
        int PlayerOneScore = 0;
        int PlayerTwoScore = 0;

        bool running = true;
        bool buttons[4] = {};

        float dt = 0.0f;        

        // error massage
        if (NULL == window)
        {
            cout << "could not create window : " << SDL_GetError() << endl;
            exit (1);
        }
        
        if(scoreFont == nullptr){
            cout << "could not load font : " << SDL_GetError() << endl;
            exit (1);
        }

        // looping until the window is close
        while (running)
        {
            auto startTime = chrono::high_resolution_clock::now();

            SDL_Event windowEvent;
            while (SDL_PollEvent(&windowEvent))
            {
                if (SDL_QUIT == windowEvent.type)
                {
                    running = false;
                    break;
                }
                else if (SDL_KEYDOWN == windowEvent.type)
                {
                    if (SDLK_ESCAPE == windowEvent.key.keysym.sym)
                    {
                        running = false;
                    }
                    else if(SDLK_w == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleOneUp] = true;
                    }
                    else if(SDLK_s == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleOneDown] = true;
                    }
                    else if(SDLK_UP == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleTwoUp] = true;
                    }
                    else if(SDLK_DOWN == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleTwoDown] = true;
                    }
                }
                else if(SDL_KEYUP == windowEvent.type)
                {
                    if(SDLK_w == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleOneUp] = false;
                    }
                    else if(SDLK_s == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleOneDown] = false;
                    }
                    else if(SDLK_UP == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleTwoUp] = false;
                    }
                    else if(SDLK_DOWN == windowEvent.key.keysym.sym)
                    {
                        buttons[Buttons::PaddleTwoDown] = false;
                    }
                }
            }

            if(buttons[Buttons::PaddleOneUp])
            {
                paddleOne.velocity.y = -PADDLE_SPEED;
            }
            else if(buttons[Buttons::PaddleOneDown])
            {
                paddleOne.velocity.y = PADDLE_SPEED;
            }
            else
            {
                paddleOne.velocity.y = 0.0f;
            }

            if(buttons[Buttons::PaddleTwoUp])
            {
                paddleTwo.velocity.y = -PADDLE_SPEED;
            }
            else if(buttons[Buttons::PaddleTwoDown])
            {
                paddleTwo.velocity.y = PADDLE_SPEED;
            }
            else
            {
                paddleTwo.velocity.y = 0.0f;
            }

            // The color of the Background
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            SDL_RenderClear(renderer);

            // The Drawing Color of the line
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            for (int y = 0; y < WINDOW_HEIGHT; y++)
            {
                if (y % 5)
                {
                    SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, y);
                }
            }

            ball.Draw(renderer);
            ball.BallUpdate(dt);

            paddleOne.Draw(renderer);
            paddleTwo.Draw(renderer);
            paddleOne.PaddleUpdate(dt);
            paddleTwo.PaddleUpdate(dt);

            playerOneScoreText.Draw();
            playerTwoScoreText.Draw();

            // Persent the backbuffer
            SDL_RenderPresent(renderer);

            //Check Collision
            if(contact = cd.checkPaddleCollision(ball, paddleOne);
                contact.type != Ball::CollisionType::None)
                {
                    ball.CollideWithPaddle(contact);

                    Mix_PlayChannel(-1, paddleHitSound, 0);
                }
                else if(contact = cd.checkPaddleCollision(ball, paddleTwo);
                contact.type != Ball::CollisionType::None)
                {
                    ball.CollideWithPaddle(contact);

                    Mix_PlayChannel(-1, paddleHitSound, 0);
                }
                else if(contact = cd.CheckWallCollision(ball);
                    contact.type != Ball::CollisionType::None)
                    {
                        ball.CollideWithWall(contact);
                        if(contact.type == Ball::CollisionType::left)
                        {
                            ++PlayerTwoScore;

                            playerTwoScoreText.SetScore(PlayerTwoScore);
                        }
                        else if(contact.type == Ball::CollisionType::right)
                        {
                            ++PlayerOneScore;

                            playerOneScoreText.SetScore(PlayerOneScore);
                        }
                        else
                        {
                            Mix_PlayChannel(-1, wallHitSound, 0);
                        }
                    }

            //Calculate frame time
            auto stopTime = chrono::high_resolution_clock::now();
            dt = chrono::duration<float , chrono::milliseconds::period>(stopTime - startTime).count();
        }
    }

    Mix_FreeChunk(wallHitSound);
    Mix_FreeChunk(paddleHitSound);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(scoreFont);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}