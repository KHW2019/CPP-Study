#include <iostream>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include "PlayerScore.h"
#include "Vec2.h"

using namespace std::chrono;

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager
{
private:

    // auto startTime = high_resolution_clock::now();
    
    // high_resolution_clock::time_point stopTime = high_resolution_clock::now();

public:
    inline static TTF_Font * scoreFont;
    TTF_Font *TitleFont;

    // float dt = 0.0f;

    const float BALL_SPEED = 1.0f;

    const int WINDOW_WIDTH = 1280, WINDOW_HEIGHT = 720;

    const int CenterLocation = SDL_WINDOWPOS_CENTERED;

    inline static SDL_Window *window;
    SDL_Renderer* renderer;

    Mix_Chunk* wallHitSound;
    Mix_Chunk* paddleHitSound;

    //problem with renderering text
    // PlayerScore playerOneNameTag = PlayerScore(Vec2(0, 20),"PlayerOne : ", renderer,scoreFont);
    // PlayerScore playerOneScore = PlayerScore(Vec2(WINDOW_WIDTH / 4.5 , 20),"0", renderer,scoreFont);
    // PlayerScore playerTwoNameTag = PlayerScore(Vec2(3 * WINDOW_WIDTH / 4.5 , 20),"PlayerTwo :", renderer,scoreFont);
    // PlayerScore playerTwoScore = PlayerScore(Vec2(3 * WINDOW_WIDTH / 3.4 , 20),"0", renderer,scoreFont);

public:

    void CreateWindow();

    void CreateRenderer();

    void CreateFont();

    void CreateSound();

    void CreateTopBar();

    void DrawTopBar();

    static void ErrorCheck();

    void startTimer();

    void stopTimer();
};

#endif