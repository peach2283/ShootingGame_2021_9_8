#pragma once

#include "Animation.h"

class ReturningPlayer : public Animation
{
private:
public:
	ReturningPlayer(float px, float py);
	~ReturningPlayer();

	void start();
};
