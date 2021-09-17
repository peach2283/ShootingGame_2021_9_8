#include "framework.h"

Gun::Gun(float px, float py) : Sprite("","",true, px, py)
{
    this->hp = 100;
}

Gun::~Gun()
{}

void Gun::start()
{
    setImage("Asset/����.bmp", 426, 315, 20, 25);
    addBoxCollider2D(2, 4, 15, 13);
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
}