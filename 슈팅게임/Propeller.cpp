#include "framework.h"

Propeller::Propeller(float px, float py) : Animation("", "", true, px, py)
{
	this->hp = 100;
}

Propeller::~Propeller()
{}

void Propeller::start()
{
	//���ؾ��� �����緯 - 0 //
	addImage("Asset/����.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/����.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//�������� �����緯 - 1//
	addImage("Asset/����.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/����.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	setImageDelay(0.1);	

	//�浹ü �߰��ϱ�
	addBoxCollider2D(8, 0, 16, 12);
}

void Propeller::onTriggerStay(GameObject* other)
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

		if (hp < 50)
		{
			setClipId(1);
		}
	}
}