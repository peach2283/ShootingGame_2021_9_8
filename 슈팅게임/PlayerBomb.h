#pragma once

#include "Animation.h"

class PlayerBomb : public Animation
{
private:
	float speed;
public:
	PlayerBomb(float px, float py);
	~PlayerBomb();

	void start();
	void update();

	void onAnimationEnd();
};