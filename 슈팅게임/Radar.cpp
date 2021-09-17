#include "framework.h"

Radar::Radar(float px, float py) : Sprite("","", true, px, py)
{
	this->hp = 100;
}

Radar::~Radar()
{}

void Radar::start()
{
	setImage("Asset/����.bmp", 360, 245, 11, 9);
	addBoxCollider2D(0, 0, 11, 9);
}

void Radar::onTriggerStay(GameObject* other)
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

void Radar::explode()
{
	//�ڽ�����//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 55, py - 60), 1);

	//�ڽİ�ü����
	destroy(this);
}