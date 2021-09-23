#pragma once

#include "Animation.h"

class BossExp : public Animation
{
private:
public:
	BossExp(float px, float py);
	~BossExp();

	void start();
	void onAnimationEnd();
};