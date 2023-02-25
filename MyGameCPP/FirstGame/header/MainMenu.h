#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Button.h"
#include "Mouse.h"
#include "GameManager.h"
#include "PlayerScore.h"

using namespace std;

#ifndef MAINMENU_H
#define MAINMENU_H

class MainMenu
{
private:
    Vec2 position;
    string text;
    SDL_Renderer* renderer;
    
	SDL_Surface* surface{};
	SDL_Texture* texture{};
	SDL_Rect StartMenuTextRect{};
    GameManager GM;  
    Button startButton = Button(Vec2(GM.WINDOW_WIDTH / 2.56, GM.WINDOW_HEIGHT / 3) , "src/include/img/Start_Button_offTrigger.png", renderer);
    Button settingsButton = Button(Vec2(GM.WINDOW_WIDTH / 2.56, GM.WINDOW_HEIGHT / 2),"src/include/img/Settings_Button_offTrigger.png", renderer);
    Button quitButton = Button(Vec2(GM.WINDOW_WIDTH / 2.56, GM.WINDOW_HEIGHT/ 1.5),"src/include/img/Quit_Button_offTrigger.png", renderer);
    Mouse mouse = Mouse(renderer);

public:
    // TTF_Font* TitleFont;
    
    MainMenu(SDL_Renderer* renderer);

    ~MainMenu();

    void Draw();

    void TopBar();

    void Update();
};

#endif
