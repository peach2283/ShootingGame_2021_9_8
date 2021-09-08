#include "framework.h"

PlayerLaserExp::PlayerLaserExp(float px, float py)
			  :Animation("","", true, px, py)
{}

PlayerLaserExp::~PlayerLaserExp()
{}

void PlayerLaserExp::start()
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			addImage("Asset/레이저폭발.bmp", col*36, row*36, 36, 36, 0);
		}
	}

	//애니메이션 속도 변경하기//
	setImageDelay(0.02);
}

void PlayerLaserExp::onAnimationEnd()
{
	//플레이어 레이저..폭발객체..삭제//
	destroy(this);
}