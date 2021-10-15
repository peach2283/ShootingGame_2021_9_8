#include "framework.h"

PlayerBombExp::PlayerBombExp(float px, float py)
			  :Animation("�÷��̾���ź����","", true, px, py)
{}

PlayerBombExp::~PlayerBombExp()
{}

void PlayerBombExp::start()
{
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			addImage("Asset/��ź����.bmp", col * 130, row * 130, 128, 128, 0);
		}
	}

	//�浹ü �߰��ϱ�//
	addBoxCollider2D(19, 19, 90, 90);
}

void PlayerBombExp::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�����Ѿ�" || tag == "������ź")
	{
		destroy(other); //�Ѿ˰�ü ����
	}
	else if (tag == "����")
	{
		float px = other->getPx();
		float py = other->getPy();

		instantiate(new ShipExp(px + 30, py + 20), 1); //��������ȿ��
		destroy(other);						           //��������

		//���� �ø���//
		GameManager::addScore(10);
	}
}

void PlayerBombExp::onAnimationEnd()
{
	destroy(this);
}