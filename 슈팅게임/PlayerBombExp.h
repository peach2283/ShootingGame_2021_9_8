#pragma once

#include "Animation.h"

class PlayerBombExp : public Animation
{
private:
public:
	PlayerBombExp(float px, float py);
	~PlayerBombExp();

	void start();
	void onTriggerStay(GameObject* other);

	void onAnimationEnd();
};