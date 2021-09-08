#include "framework.h"

EnemyBulletExp::EnemyBulletExp(float px, float py)
			  :Animation("","",true, px, py)
{}

EnemyBulletExp::~EnemyBulletExp()
{}

void EnemyBulletExp::start()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			addImage("Asset/�Ѿ�����.bmp", col * 40, row * 40, 40, 40, 0);
		}
	}
}

void EnemyBulletExp::onAnimationEnd()
{
	destroy(this);
}