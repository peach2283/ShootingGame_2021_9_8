#pragma once

#include "Sprite.h"

class Gun : public Sprite
{
private:
	float hp;
public:
	Gun(float px, float py);
	~Gun();

	void start();
	void onTriggerStay(GameObject* other);

	void explode();
};