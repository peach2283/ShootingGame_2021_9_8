#pragma once

#include "Sprite.h"

class LaserItem : public Sprite
{
private:
public:
	LaserItem(float px, float py);
	~LaserItem();

	void start();
	void onTriggerStay(GameObject* other);
};