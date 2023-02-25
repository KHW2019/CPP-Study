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
#include "MainMenu.h"
#include "GameManager.h"
#include "inGame.h"

using namespace std;
using namespace std::chrono;

// enum Buttons
// {
//     PaddleOneUp = 0,
//     PaddleOneDown,
//     PaddleTwoUp,
//     PaddleTwoDown,
// };

// const int WINDOW_WIDTH = 1280, WINDOW_HEIGHT = 720;

// int CenterLocation = SDL_WINDOWPOS_CENTERED;
const float BALL_SPEED = 1.0f;

CollisionDetection cd;
Ball::Contact contact;
GameManager GM;
inGame GameSection;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); 
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    GM.CreateWindow();
   
    GM.CreateRenderer();

    GM.CreateFont();

    GM.CreateSound();

    // GameSection.CreateTopBar();
    
    // MainMenu startMenu(renderer);
    
    // Mouse mouse(renderer);

    //TopBar
    PlayerScore playerOneNameTag(Vec2(0, 20),"PlayerOne : ", GM.renderer,GM.scoreFont);
    PlayerScore playerOneScore(Vec2(GM.WINDOW_WIDTH / 4.5 , 20),"0", GM.renderer,GM.scoreFont);
    PlayerScore playerTwoNameTag(Vec2(3 * GM.WINDOW_WIDTH / 4.5 , 20),"PlayerTwo :", GM.renderer,GM.scoreFont);
    PlayerScore playerTwoScore(Vec2(3 * GM.WINDOW_WIDTH / 3.4 , 20),"0", GM.renderer,GM.scoreFont);

    // Ball ball(
    //     Vec2(GM.WINDOW_WIDTH / 2.0f, GM.WINDOW_HEIGHT/ 2.0f), 
    //     Vec2(Ball::BALL_SPEED, 0.0f));
        
    // Paddle paddleOne(Vec2(50.0f, GM.WINDOW_HEIGHT / 2.0f), Vec2(0.0f, 0.0f));

    // Paddle paddleTwo(Vec2(GM.WINDOW_WIDTH - 50.0f, GM.WINDOW_HEIGHT /2.0f), Vec2(0.0f, 0.0f));

    {
        int PlayerOneScore = 0;
        int PlayerTwoScore = 0;

        bool running = true;
        bool paused = false;
        // bool buttons[4] = {};

        float dt = 0.0f;

        // error massage
       
        GameManager::ErrorCheck();

        // if(GM.scoreFont == nullptr){
        //     cout << "could not load score font : " << SDL_GetError() << endl;
        //     exit (1);
        // }

        // looping until the window is close
        while (running)
        {
            // GM.startTimer();
            auto startTime = high_resolution_clock::now();
            
            SDL_Event windowEvent;
            while (SDL_PollEvent(&windowEvent))
            {
                switch (windowEvent.type)
                {
                default:
                    break;

                case SDL_QUIT:
                    running = false;
                    break;
                    
                case SDL_KEYDOWN:
                    if (SDLK_ESCAPE == windowEvent.key.keysym.sym)
                    {
                        running = false;
                    }
                    else if (SDLK_w == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleOneUp] = true;
                        break;
                    }
                    else if (SDLK_s == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleOneDown] = true;
                        break;
                    }
                    else if (SDLK_UP == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleTwoUp] = true;
                        break;
                    }
                    else if (SDLK_DOWN == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleTwoDown] = true;
                        break;
                    }
                case SDL_KEYUP:
                    if (SDLK_w == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleOneUp] = false;
                        break;
                    }
                    else if (SDLK_s == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleOneDown] = false;
                        break;
                    }
                    else if (SDLK_UP == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleTwoUp] = false;
                        break;
                    }
                    else if (SDLK_DOWN == windowEvent.key.keysym.sym)
                    {
                        GameSection.buttons[GameSection.Buttons::PaddleTwoDown] = false;
                        break;
                    }
                case SDL_MOUSEBUTTONUP:
                    if (windowEvent.button.button == SDL_BUTTON_LEFT)
                    {
                        // if (startButton.isSelected)
                        // {
                        //     cout << "StartButton has been Clicked" << endl;
                        // }
                        // else if (settingsButton.isSelected)
                        // {
                        //     cout << "OptionButton has been Clicked" << endl;
                        // }
                        // else if (quitButton.isSelected)
                        // {
                        //     running = false;
                        //     return 0;
                        // }
                    }
                }

                GameSection.PlayerController();

                // if (buttons[Buttons::PaddleOneUp])
                // {
                //        paddleOne.velocity.y = -paddleOne.PADDLE_SPEED;
                // }
                // else if (buttons[Buttons::PaddleOneDown])
                // {
                //        paddleOne.velocity.y = paddleOne.PADDLE_SPEED;
                // }
                // else
                // {
                //        paddleOne.velocity.y = 0.0f;
                // }

                // if (buttons[Buttons::PaddleTwoUp])
                // {
                //        paddleTwo.velocity.y = -paddleTwo.PADDLE_SPEED;
                // }
                // else if (buttons[Buttons::PaddleTwoDown])
                // {
                //        paddleTwo.velocity.y = paddleTwo.PADDLE_SPEED;
                // }
                // else
                // {
                //        paddleTwo.velocity.y = 0.0f;
                // }
            }

            // The color of the Background
            SDL_SetRenderDrawColor(GM.renderer, 160, 160, 0, 160);
            SDL_RenderClear(GM.renderer);

             // The Drawing Color of the line
            // SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            // for (int y = 0; y < GM.WINDOW_HEIGHT; y++)
            // {
            //     if (y % 5)
            //     {
            //         SDL_RenderDrawPoint(renderer, GM.WINDOW_WIDTH / 2, y);
            //     }
            // }

            // startButton.Draw();
            // startButton.Update(mouseT, "src/include/img/Start_Button_onTrigger.png");
            // settingsButton.Draw();
            // settingsButton.Update(mouseT, "src/include/img/Settings_Button_onTrigger.png");
            // quitButton.Draw();
            // quitButton.Update(mouseT, "src/include/img/Quit_Button_onTrigger.png");

            // mouse.Draw();
            // mouse.Update();

            // ball.Draw(renderer);
            // ball.BallUpdate(dt);

            // paddleOne.Draw(renderer);
            // paddleOne.PaddleUpdate(dt);
            // paddleTwo.Draw(renderer);
            // paddleTwo.PaddleUpdate(dt);

            // GameSection.DrawTopBar(GM.renderer);
            GameSection.Draw(GM.renderer);
            GameSection.Update(dt);

            playerOneNameTag.Draw();
            playerOneScore.Draw();
            playerTwoNameTag.Draw();
            playerTwoScore.Draw();

            // startMenu.Draw();
            // startMenu.Update();

            // Persent the backbuffer
            SDL_RenderPresent(GM.renderer);

            GameSection.CheckCollision();

            // if (contact = cd.checkPaddleCollision(GameSection.ball, GameSection.paddleOne);
            //     contact.type != Ball::CollisionType::None)
            // {
            //     GameSection.ball.CollideWithPaddle(contact);

            //     Mix_PlayChannel(-1, paddleHitSound, 0);
            // }
            // else if (contact = cd.checkPaddleCollision(GameSection.ball, GameSection.paddleTwo);
            //          contact.type != Ball::CollisionType::None)
            // {
            //     GameSection.ball.CollideWithPaddle(contact);

            //     Mix_PlayChannel(-1, paddleHitSound, 0);
            // }
            // else if (contact = cd.CheckWallCollision(GameSection.ball);
            //          contact.type != Ball::CollisionType::None)
            // {
            //     GameSection.ball.CollideWithWall(contact);
            //     if (contact.type == Ball::CollisionType::left)
            //     {
            //            ++GameSection.PlayerTwoScore;

            //            playerTwoScore.SetScore(GameSection.PlayerTwoScore);
            //     }
            //     else if (contact.type == Ball::CollisionType::right)
            //     {
            //            ++GameSection.PlayerOneScore;

            //            playerOneScore.SetScore(GameSection.PlayerOneScore);
            //     }
            //     else
            //     {
            //            Mix_PlayChannel(-1, wallHitSound, 0);
            //     }
            // }

            //Calculate frame time
            // GM.stopTimer();
            auto stopTime = high_resolution_clock::now();
            dt = duration<float , milliseconds::period>(stopTime - startTime).count();
        }
    }

    Mix_FreeChunk(GM.wallHitSound);
    Mix_FreeChunk(GM.paddleHitSound);
    SDL_DestroyRenderer(GM.renderer);
    SDL_DestroyWindow(GM.window);
    TTF_CloseFont(GM.scoreFont);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}