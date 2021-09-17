#include "framework.h"

Propeller::Propeller(float px, float py) : Animation("", "", true, px, py)
{
	this->hp = 100;
}

Propeller::~Propeller()
{}

void Propeller::start()
{
	//피해없는 프로펠러 - 0 //
	addImage("Asset/보스.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//피해입은 프로펠러 - 1//
	addImage("Asset/보스.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	setImageDelay(0.1);	

	//충돌체 추가하기
	addBoxCollider2D(8, 0, 16, 12);
}

void Propeller::onTriggerStay(GameObject* other)
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

		if (0 < hp && hp < 50)
		{
			setClipId(1);
		}
		else if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "플레이어폭탄폭발")
	{
		explode();
	}
}

void Propeller::explode()
{
	//자식폭발//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 40, py - 40), 1);

	//자식객체제거
	destroy(this);

	//부모 보스객체에...제거되었음을 알려줌
	Boss* boss = (Boss*)getParent();
	boss->onChildDestroyed();
}