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
	addChildObject(new Gun(94,  71), 0);
	addChildObject(new Gun(142, 71), 0);
	addChildObject(new Gun(190, 71), 0);

	addChildObject(new Gun(238, 63), 0);

	addChildObject(new Gun(286, 71), 0);
	addChildObject(new Gun(334, 71), 0);
	addChildObject(new Gun(382, 71), 0);

	//�����Ʒ� ���� �ڽİ�ü
	addChildObject(new Cannon(265 + 5, 97 + 10), 0);
	addChildObject(new Cannon(206 - 5, 97 + 10), 0);

	//���̴� �ڽİ�ü
	addChildObject(new Radar(241, 105), 0);
	addChildObject(new Radar(241, 117), 0);
}

void Boss::onChildDestroyed()
{
	childCount++;

	cout << "�Ҹ�� �ڽİ�ü ���� " << childCount <<  endl;

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
	}
}