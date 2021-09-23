#include "framework.h"

BossExp::BossExp(float px, float py) : Animation("","",true, px, py)
{}

BossExp::~BossExp()
{}

void BossExp::start()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			addImage("Asset/Æø¹ßÈ¿°ú.bmp", 161*col, 7482 + 161*row, 160, 160, 0);
		}
	}
}

void BossExp::onAnimationEnd()
{
	destroy(this);
}