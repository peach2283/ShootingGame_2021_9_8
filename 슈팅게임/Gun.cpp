#include "framework.h"

Gun::Gun(float px, float py) : Sprite("","",true, px, py)
{
    this->hp = 100;
}

Gun::~Gun()
{}

void Gun::start()
{
    setImage("Asset/보스.bmp", 426, 315, 20, 25);
    addBoxCollider2D(2, 4, 15, 13);
}

void Gun::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "플레이어레이저")
	{
		//플레이어 레이저..폭발효과//
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new PlayerLaserExp(ex - 15, ey - 15), 1);

		//플레이어 레이저..제거하기//
		destroy(other);

		//체력 감소 및 애니메이션 변경
		hp = hp - 10;
	
		if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "플레이어폭탄폭발")
	{
		explode();
	}
}

void Gun::explode()
{
	//자식폭발//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 50, py - 40), 1);

	//자식객체제거
	destroy(this);
}