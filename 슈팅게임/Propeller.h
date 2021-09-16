#pragma once

#include "Animation.h"

class Propeller : public Animation
{
private:
	float hp;
public:
	Propeller(float px, float py);
	~Propeller();

	void start();
	void onTriggerStay(GameObject* other);
};