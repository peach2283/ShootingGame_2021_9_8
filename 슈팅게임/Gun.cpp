#include "framework.h"

Gun::Gun(string name, float px, float py) : Sprite("",name,true, px, py)
{
    this->hp = 100;

	//this->fireTimer = 0;
	//this->fireDelay = 1;
}

Gun::~Gun()
{}

void Gun::start()
{
    setImage("Asset/보스.bmp", 426, 315, 20, 25);
    addBoxCollider2D(2, 4, 15, 13);
}

void Gun::update()
{
	//fireTimer = fireTimer + Time::deltaTime;

	//if (fireTimer >= fireDelay)
	//{
	//	float px = getPx();
	//	float py = getPy();

	//	instantiate(new EnemyBullet(px+1, py+20), 0);

	//	fireTimer = 0;
	//}
}

void Gun::onFire()
{
	float px = getPx();
	float py = getPy();

	instantiate(new EnemyBullet(px+1, py+20), 0);
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

	//부모 보스객체에...제거되었음을 알려줌
	Boss* boss = (Boss*)getParent();
	boss->onChildDestroyed();
}