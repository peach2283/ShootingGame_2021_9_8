#pragma once

#include "Sprite.h"

class Cannon : public Sprite
{
private:
	float hp;

public:
	Cannon(string name, float px, float py);
	~Cannon();

	void start();
	void onTriggerStay(GameObject* other);

	void explode();

	void onFire();
};