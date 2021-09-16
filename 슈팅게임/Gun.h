#pragma once

#include "Sprite.h"

class Gun : public Sprite
{
private:
public:
	Gun(float px, float py);
	~Gun();

	void start();
};