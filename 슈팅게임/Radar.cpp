#include "framework.h"

Radar::Radar(float px, float py) : Sprite("","", true, px, py)
{
	this->hp = 100;
}

Radar::~Radar()
{}

void Radar::start()
{
	setImage("Asset/보스.bmp", 360, 245, 11, 9);
	addBoxCollider2D(0, 0, 11, 9);
}

void Radar::onTriggerStay(GameObject* other)
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

void Radar::explode()
{
	//자식폭발//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 55, py - 60), 1);

	//자식객체제거
	destroy(this);
}