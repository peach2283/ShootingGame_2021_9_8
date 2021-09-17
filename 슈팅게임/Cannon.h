#pragma once

#include "Sprite.h"

class Cannon : public Sprite
{
private:
	float hp;

public:
	Cannon(float px, float py);
	~Cannon();

	void start();
	void onTriggerStay(GameObject* other);

	void explode();
};