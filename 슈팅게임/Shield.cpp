#include "framework.h"

Shield::Shield(float px, float py) :Animation("방패","방패", true , px, py)
{}

Shield::~Shield()
{}

void Shield::start()
{
	addImage("Asset/보호방패1.bmp", 0);
	addImage("Asset/보호방패2.bmp", 0);
	addImage("Asset/보호방패3.bmp", 0);

	//충돌체 추가하기//
	addBoxCollider2D(10, 10, 70, 70);
}

void Shield::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "적기총알" || tag == "적기포탄")
	{
		//적기 총알제하기
		destroy(other);

		//총알 폭발 효과
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new EnemyBulletExp(ex - 10, ey), 1);
	}
	else if (tag == "적기")
	{
		float px = other->getPx();
		float py = other->getPy();

		instantiate(new ShipExp(px + 30, py + 20), 1); //적기폭발효과
		destroy(other);						           //적기제거
	}
	else if (tag == "보스")
	{
	    //보호방패 제거하기//
		setActive(false);
	}
}