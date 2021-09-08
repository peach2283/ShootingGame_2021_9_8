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
			addImage("Asset/����������.bmp", col*36, row*36, 36, 36, 0);
		}
	}

	//�ִϸ��̼� �ӵ� �����ϱ�//
	setImageDelay(0.02);
}

void PlayerLaserExp::onAnimationEnd()
{
	//�÷��̾� ������..���߰�ü..����//
	destroy(this);
}