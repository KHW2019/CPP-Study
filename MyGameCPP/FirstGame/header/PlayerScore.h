#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Vec2.h"

#ifndef PlayerScore_H
#define PlayerScore_H

class PlayerScore
{
private:
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Surface* surface{};
	SDL_Texture* texture{};
	SDL_Rect PlayerScoreRect{};

public:
	PlayerScore(Vec2 position, SDL_Renderer* renderer, TTF_Font* font);

	~PlayerScore();

	void Draw();

	void SetScore(int score);
};

#endif