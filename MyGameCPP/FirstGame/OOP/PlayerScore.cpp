#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "PlayerScore.h"
#include "Vec2.h"


using namespace std;

PlayerScore::PlayerScore(Vec2 position,string PlayerScoreText, SDL_Renderer *renderer, TTF_Font* Font)
	: renderer(renderer), Font(Font)
{
	SDL_Color Color = {255, 255, 255, 255};

	surface = TTF_RenderText_Solid(Font, PlayerScoreText.c_str(), Color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	PlayerScoreRect.x = static_cast<int>(position.x);
	PlayerScoreRect.y = static_cast<int>(position.y);
	PlayerScoreRect.w = width;
	PlayerScoreRect.h = height;
}

PlayerScore::~PlayerScore()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void PlayerScore::Draw()
{
	SDL_RenderCopy(renderer, texture, nullptr, &PlayerScoreRect);
}

void PlayerScore::SetScore(int Score)
{
	PlayerScore::~PlayerScore();

	surface = TTF_RenderText_Solid(Font, to_string(Score).c_str(),{0xFF,0xFF,0xFF,0xFF});
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	PlayerScoreRect.w = width;
	PlayerScoreRect.h = height;
}