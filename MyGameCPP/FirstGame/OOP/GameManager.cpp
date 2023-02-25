#include "GameManager.h"

using namespace std;

void GameManager::CreateWindow()
{
    window = SDL_CreateWindow("Pong", CenterLocation, CenterLocation, WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
}

void GameManager::CreateRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void GameManager::CreateFont()
{
    scoreFont = TTF_OpenFont("src/include/dejavu-fonts-ttf/ttf/DejaVuSansMono.ttf", 40);
    TitleFont = TTF_OpenFont("src/include/dejavu-fonts-ttf/ttf/DejaVuSerif-Bold.ttf", 100);
}

void GameManager::CreateSound()
{
    wallHitSound = Mix_LoadWAV("src/include/Sound/WallHit.wav");
    paddleHitSound = Mix_LoadWAV("src/include/Sound/PaddleHit.wav");
}

void GameManager::CreateTopBar() 
{
    // PlayerScore playerOneNameTag = PlayerScore(Vec2(0, 20),"PlayerOne : ", renderer,scoreFont);
    // PlayerScore playerOneScore = PlayerScore(Vec2(WINDOW_WIDTH / 4.5 , 20),"0", renderer,scoreFont);
    // PlayerScore playerTwoNameTag = PlayerScore(Vec2(3 * WINDOW_WIDTH / 4.5 , 20),"PlayerTwo :", renderer,scoreFont);
    // PlayerScore playerTwoScore = PlayerScore(Vec2(3 * WINDOW_WIDTH / 3.4 , 20),"0", renderer,scoreFont);
}

void GameManager::DrawTopBar()
{
    // playerOneNameTag.Draw();
    // playerOneScore.Draw();
    // playerTwoNameTag.Draw();
    // playerTwoScore.Draw();
}

// void GameManager::startTimer()
// {
//     startTime;
// }

// void GameManager::stopTimer()
// {
//     stopTime;
//     dt = chrono::duration<float , chrono::milliseconds::period>(stopTime - startTime).count();
// }

void GameManager::ErrorCheck()
{
    if(TTF_Init() == -1){
        cout<< "TTF INIT Error : " << TTF_GetError() << endl; 
    }
    
    if (NULL == window)
    {
        cout << "could not create window : " << SDL_GetError() << endl;
        exit(1);
    }
        

    if(scoreFont == nullptr){
        cout << "could not load score font : " << SDL_GetError() << endl;
        exit (1);
    }

    // if(TitleFont == nullptr){
    //     cout << "could not load Title font : " << SDL_GetError() << endl;
    //     exit (1);
    // }
}