#include "framework.h"

Shield::Shield(float px, float py) :Animation("����","����", true , px, py)
{}

Shield::~Shield()
{}

void Shield::start()
{
	addImage("Asset/��ȣ����1.bmp", 0);
	addImage("Asset/��ȣ����2.bmp", 0);
	addImage("Asset/��ȣ����3.bmp", 0);

	//�浹ü �߰��ϱ�//
	addBoxCollider2D(10, 10, 70, 70);
}

void Shield::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�����Ѿ�" || tag == "������ź")
	{
		//���� �Ѿ����ϱ�
		destroy(other);

		//�Ѿ� ���� ȿ��
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new EnemyBulletExp(ex - 10, ey), 1);
	}
	else if (tag == "����")
	{
		float px = other->getPx();
		float py = other->getPy();

		instantiate(new ShipExp(px + 30, py + 20), 1); //��������ȿ��
		destroy(other);						           //��������
	}
	else if (tag == "����")
	{
	    //��ȣ���� �����ϱ�//
		setActive(false);
	}
}