#pragma once

#include "Sprite.h"

class Boss : public Sprite
{
private:
public:
	Boss(float px, float py);
	~Boss();

	void start();
};
