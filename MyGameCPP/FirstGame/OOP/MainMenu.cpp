#include <iostream>
#include <SDL2/SDL.h>
#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu(SDL_Renderer* renderer)
    : renderer(renderer)
{   
    TopBar(); 
}

MainMenu::~MainMenu()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void MainMenu::Draw()
{
    SDL_RenderCopy(renderer, texture, nullptr, &StartMenuTextRect);

    mouse.Draw();

    startButton.Draw();
    settingsButton.Draw();
    quitButton.Draw();

}

void MainMenu::TopBar()
{
    SDL_Color color = {255,255,255,255};

    GM.CreateFont();
    
    surface = TTF_RenderText_Solid(GM.TitleFont, "Pong", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int width, height;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    StartMenuTextRect.x = GM.WINDOW_WIDTH /2.5;
	StartMenuTextRect.y = GM.WINDOW_HEIGHT / 10;
	StartMenuTextRect.w = width;
	StartMenuTextRect.h = height;
}

void MainMenu::Update()
{
    //update mouse position
    mouse.Update();

    // //update on mouse collision
    startButton.Update(mouse, "src/include/img/Start_Button_onTrigger.png");
    settingsButton.Update(mouse, "src/include/img/Settings_Button_onTrigger.png");
    quitButton.Update(mouse, "src/include/img/Quit_Button_onTrigger.png");

    
}

