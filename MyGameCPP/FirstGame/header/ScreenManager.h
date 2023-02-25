#include <iostream>
#include <SDL2/SDL.h>

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

class ScreenManager
{
private:

public:
enum class gameStatus
{
    StartMenu,
    InGame,
    PauseGame
};

struct switchscreen
{
    gameStatus status;
};

    ScreenManager();

    ~ScreenManager();
};

#endif