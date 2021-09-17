#include "framework.h"

Cannon::Cannon(float px, float py) : Sprite("","",true, px, py)
{
	this->hp = 100;
}

Cannon::~Cannon()
{}

void Cannon::start()
{
	setImage("Asset/����.bmp", 357, 262, 21, 22);
	addBoxCollider2D(0, 0, 21, 10);
}

void Cannon::onTriggerStay(GameObject* other)
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

void Cannon::explode()
{
	//�ڽ�����//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 50, py - 60), 1);

	//�ڽİ�ü����
	destroy(this);

	//�θ� ������ü��...���ŵǾ����� �˷���
	Boss* boss = (Boss*)getParent();
	boss->onChildDestroyed();
}