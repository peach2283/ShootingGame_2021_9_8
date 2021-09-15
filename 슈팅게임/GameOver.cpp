#include "framework.h"

GameOver::GameOver(float px, float py)
		:Sprite("","", true, px, py)
{}

GameOver::~GameOver()
{}

void GameOver::start()
{
	setImage("Asset/게임오버.bmp");
}