#pragma once

#include "Sprite.h"

class Radar : public Sprite
{
private:
public:
	Radar(float px, float py);
	~Radar();

	void start();
};