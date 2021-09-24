#pragma once

#include "Sprite.h"

class Gun : public Sprite
{
private:
	float hp;

	//float fireTimer;
	//float fireDelay;

public:
	Gun(string name, float px, float py);
	~Gun();

	void start();
	void update();

	void onTriggerStay(GameObject* other);
	void explode();
};