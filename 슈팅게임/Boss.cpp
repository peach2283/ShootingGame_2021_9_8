#include "framework.h"

Boss::Boss(float px, float py) :Sprite("����", "", true, px, py)
{
	this->childCount = 0;
}

Boss::~Boss()
{}

void Boss::start()
{
	//���ߵ��� ���� ����
	setImage("Asset/����.bmp", 0, 0, 493, 206);

	//**************���� �ڽİ�ü �߰��ϱ�***************//
	//�����緯 �ڽİ�ü
	addChildObject(new Propeller(63,  41), 0);
	addChildObject(new Propeller(111, 41), 0);
	addChildObject(new Propeller(159, 41), 0);

	addChildObject(new Propeller(302, 41), 0);
	addChildObject(new Propeller(350, 41), 0);
	addChildObject(new Propeller(398, 41), 0);

	//���� �ڽİ�ü
	addChildObject(new Wing(298, 425, 30, 18,     256, 97), 0);  //������ ù��°
	addChildObject(new Wing(329, 426, 32, 16,     302, 94), 0);  //������ �ι�°
	addChildObject(new Wing(364, 426, 32, 16,	  350, 90), 0);  //������ ����°
	addChildObject(new Wing(399, 426, 32, 16,     405, 84), 0);  //������ �׹�°

	addChildObject(new Wing(404, 406, 28, 15,	  206, 98), 0);  //����  ù��°
	addChildObject(new Wing(369, 406, 32, 16,	  158, 94), 0);  //����  �ι�°
	addChildObject(new Wing(334, 406, 32, 16,	  110, 90), 0);  //����  ����°
	addChildObject(new Wing(299, 406, 32, 16,	   62, 85), 0);  //����  �׹�°

	//������ �� �ڽİ�ü
	addChildObject(new Gun("��1", 94,  71), 0); //��1
	addChildObject(new Gun("��2", 142, 71), 0); //��2
	addChildObject(new Gun("��3", 190, 71), 0); //��3

	addChildObject(new Gun("��4", 238, 63), 0); //��4

	addChildObject(new Gun("��5", 286, 71), 0); //��5
	addChildObject(new Gun("��6", 334, 71), 0); //��6
	addChildObject(new Gun("��7", 382, 71), 0); //��7

	//�����Ʒ� ���� �ڽİ�ü
	addChildObject(new Cannon(265 + 5, 97 + 10), 0);
	addChildObject(new Cannon(206 - 5, 97 + 10), 0);

	//���̴� �ڽİ�ü
	addChildObject(new Radar(241, 105), 0);
	addChildObject(new Radar(241, 117), 0);

	//���� ��ü...�浹ü//
	addBoxCollider2D(230,  10, 33,  160);
	addBoxCollider2D(10,   60, 473, 40);
	addBoxCollider2D(190, 170, 113, 30);
}

void Boss::onChildDestroyed()
{
	childCount++;

	cout << "�Ҹ�� �ڽİ�ü ���� " << childCount <<  endl;

	//if (childCount == 25)
	if (childCount == 1)
	{
		float px = getPx();
		float py = getPy();

		//���� ���� ��Ű��
		instantiate(new BossExp(px + 165, py -30), 1);

		instantiate(new BossExp(px + 25,  py), 1);
		instantiate(new BossExp(px + 305, py), 1);

		instantiate(new BossExp(px + 165, py+70), 1);

		//���� �����ϱ�
		destroy(this); 

		//���ߵ� ���� ��ü(DeadBoss) �����ϱ�//		
		instantiate(new DeadBoss(px+47, py+20), 0);

		//������..�׾��� ���ӸŴ��� ���� ������..ǥ��
		//GameManager::setBossDead();

		//�÷��̾ ã�Ƽ�..������ �׾�����..���� �˷���
		Player * player =(Player *) ObjectManager::find("�÷��̾�");

		if (player != nullptr)
		{
			player->onBossDestroyed();
		}
		else {
			cout << "===�÷��̾� ��ü�� ã�� ����===" << endl;
		}
	}
}