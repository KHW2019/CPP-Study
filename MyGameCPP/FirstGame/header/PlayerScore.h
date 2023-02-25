#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Vec2.h"

using namespace std;

#ifndef PlayerScore_H
#define PlayerScore_H

class PlayerScore
{
private:
	string PlayerScoreText;
	SDL_Renderer* renderer;
	TTF_Font* Font;
	SDL_Surface* surface{};
	SDL_Texture* texture{};
	SDL_Rect PlayerScoreRect{};
	
public:
	PlayerScore(Vec2 position,string PlayerScoreText, SDL_Renderer* renderer, TTF_Font* Font);

	~PlayerScore();

	void Draw();

	void SetScore(int score);
};

#endif