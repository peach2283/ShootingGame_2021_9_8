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
    setImage("Asset/����.bmp", 426, 315, 20, 25);
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

	if (tag == "�÷��̾����")
	{
		//�÷��̾� ������..����ȿ��//
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new PlayerLaserExp(ex - 15, ey - 15), 1);

		//�÷��̾� ������..�����ϱ�//
		destroy(other);

		//ü�� ���� �� �ִϸ��̼� ����
		hp = hp - 10;
	
		if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "�÷��̾���ź����")
	{
		explode();
	}
}

void Gun::explode()
{
	//�ڽ�����//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 50, py - 40), 1);

	//�ڽİ�ü����
	destroy(this);

	//�θ� ������ü��...���ŵǾ����� �˷���
	Boss* boss = (Boss*)getParent();
	boss->onChildDestroyed();
}