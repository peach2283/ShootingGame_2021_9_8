#pragma once

#include "Sprite.h"

class Cannon : public Sprite
{
private:
public:
	Cannon(float px, float py);
	~Cannon();

	void start();
};