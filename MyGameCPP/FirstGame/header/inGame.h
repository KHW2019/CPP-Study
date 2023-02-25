#include <iostream>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Ball.h"
#include "GameManager.h"
#include "Paddle.h"
#include "PlayerScore.h"
#include "CollisionDetection.h"


#ifndef INGAME_H
#define INGAME_H

class inGame
{
private:
    GameManager GM; 
    CollisionDetection cd;
    Ball::Contact contact;

public:
    enum Buttons
    {
        PaddleOneUp = 0,
        PaddleOneDown,
        PaddleTwoUp,
        PaddleTwoDown,
    };

    bool buttons[4] = {};

    // float dt = 0.0f;

    SDL_Renderer* GameObjectRenderer;

    Ball ball = Ball(Vec2(GM.WINDOW_WIDTH / 2.0f, GM.WINDOW_HEIGHT/ 2.0f),Vec2(GM.BALL_SPEED, 0.0f));

    Paddle paddleOne = Paddle(Vec2(50.0f, GM.WINDOW_HEIGHT / 2.0f), Vec2(0.0f, 0.0f));

    Paddle paddleTwo = Paddle(Vec2(GM.WINDOW_WIDTH - 50.0f, GM.WINDOW_HEIGHT /2.0f), Vec2(0.0f, 0.0f));

    // Mix_Chunk* wallHitSound = Mix_LoadWAV("src/include/Sound/WallHit.wav");
    // Mix_Chunk* paddleHitSound = Mix_LoadWAV("src/include/Sound/PaddleHit.wav");

    PlayerScore playerOneNameTag = PlayerScore(Vec2(0, 20),"PlayerOne : ", GameObjectRenderer,GM.scoreFont);
    PlayerScore playerOneScore = PlayerScore(Vec2(GM.WINDOW_WIDTH / 4.5 , 20),"0", GameObjectRenderer, GM.scoreFont);
    PlayerScore playerTwoNameTag = PlayerScore(Vec2(3 * GM.WINDOW_WIDTH / 4.5 , 20),"PlayerTwo :", GameObjectRenderer,GM.scoreFont);
    PlayerScore playerTwoScore = PlayerScore(Vec2(3 * GM.WINDOW_WIDTH / 3.4 , 20),"0", GameObjectRenderer,GM.scoreFont);

    int PlayerOneScore = 0;
    int PlayerTwoScore = 0;

public:

    void CreateTopBar();
    
    void DrawTopBar(SDL_Renderer* renderer);

    void Draw(SDL_Renderer* renderer);

    void Update(float dt);

    void CheckCollision();

    void PlayerController();
};

#endif