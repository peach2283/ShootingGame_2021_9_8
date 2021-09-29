#pragma once

#include "Sprite.h"

class Button : public Sprite
{
private:
public:
	Button(float px, float py);
	~Button();

	void start();
	void update();
};
