#pragma once

#include "Animation.h"

class PlayerLaserExp : public Animation
{
private:
public:
	PlayerLaserExp(float px, float py);
	~PlayerLaserExp();

	void start();

	//�ִϸ��̼� �̺�Ʈ..�������̵�//
	void onAnimationEnd();
};