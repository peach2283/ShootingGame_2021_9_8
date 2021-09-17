#pragma once

#include "Sprite.h"

class Radar : public Sprite
{
private:
	float hp;

public:
	Radar(float px, float py);
	~Radar();

	void start();
	void onTriggerStay(GameObject* other);

	void explode();
};