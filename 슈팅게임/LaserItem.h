#pragma once

#include "Sprite.h"

class LaserItem : public Sprite
{
private:
	float speed;
	float lifeTime;
public:
	LaserItem(float px, float py);
	~LaserItem();

	void start();
	void update();

	void onTriggerStay(GameObject* other);
};