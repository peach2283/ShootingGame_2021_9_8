#pragma once

#include "Sprite.h"

class PlayerLaser : public Sprite
{
private:
	float speed;
	float lifeTime;
public:
	PlayerLaser(float px, float py);
	~PlayerLaser();

	void start();
	void update();
};
