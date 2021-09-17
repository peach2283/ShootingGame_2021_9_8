#include "framework.h"

Cannon::Cannon(float px, float py) : Sprite("","",true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::start()
{
	setImage("Asset/보스.bmp", 357, 262, 21, 22);
	addBoxCollider2D(0, 0, 21, 10);
}

void Cannon::onTriggerStay(GameObject* other)
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

void Cannon::explode()
{
	//자식폭발//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 50, py - 60), 1);

	//자식객체제거
	destroy(this);

	//부모 보스객체에...제거되었음을 알려줌
	Boss* boss = (Boss*)getParent();
	boss->onChildDestroyed();
}