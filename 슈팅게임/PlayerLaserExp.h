#pragma once

#include "Animation.h"

class PlayerLaserExp : public Animation
{
private:
public:
	PlayerLaserExp(float px, float py);
	~PlayerLaserExp();

	void start();

	//애니메이션 이벤트..오버라이딩//
	void onAnimationEnd();
};