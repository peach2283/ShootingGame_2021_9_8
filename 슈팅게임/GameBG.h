#pragma once

#include "Sprite.h"

class GameBG : public Sprite
{
private:
public:
	GameBG();
	~GameBG();

	void start();
	void update();
};