#pragma once

#include "Animation.h"

class ReturningPlayer : public Animation
{
private:
	float speed;
public:
	ReturningPlayer(float px, float py);
	~ReturningPlayer();

	void start();
	void update();
};
