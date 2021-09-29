#include "framework.h"

Boss::Boss(float px, float py) :Sprite("����", "", true, px, py)
{
	this->childCount = 0;

	this->gunFireTimer	= 0;
	this->gunFireDelay	= 0.2;
	this->gunFireIndex	= 0;

	this->cannonFireTimer = 0;
	this->cannonFireDelay = 0.5;
	this->cannonFireIndex = 0;

	this->speed = 50;
	this->state = State::moveDown;

	this->attackPos = 60;
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
	addChildObject(new Cannon("����1", 265 + 5, 97 + 10), 0); //����1
	addChildObject(new Cannon("����2", 206 - 5, 97 + 10), 0); //����2

	//���̴� �ڽİ�ü
	addChildObject(new Radar(241, 105), 0);
	addChildObject(new Radar(241, 117), 0);

	//���� ��ü...�浹ü//
	addBoxCollider2D(230,  10, 33,  160);
	addBoxCollider2D(10,   60, 473, 40);
	addBoxCollider2D(190, 170, 113, 30);
}

void Boss::update()
{
	switch (state)
	{	
		case State::moveDown :
		{
			//�̵��ϱ�
			move();

			//�ǹ߻��ϱ�
			bulletFire();

			//�����ϰ� ���ݻ��� ���� ���ǰ˻�
			int py = getPy();

			if (py >= attackPos)
			{
				state = State::attack;
			}
		}
		break;

		case State::attack :
		{
			//�����ϱ�
			bulletFire();
			shellFire();
		}
		break;
	}
}

void Boss::move()
{
	//�̵��ϱ�
	float dist = speed * Time::deltaTime;
	translate(0, dist);
}

void Boss::bulletFire()
{
	//�ǹ߻��ϱ�
	gunFireTimer = gunFireTimer + Time::deltaTime;

	if (gunFireTimer >= gunFireDelay)
	{
		//�ڽİ� ã��
		string name[7] = { "��1", "��2", "��3", "��4", "��5", "��6", "��7" };

		for (int i = 0; i < 7; i++)
		{
			if (gunFire[i][gunFireIndex] == true)  //�ǹ迭����..�߻��..����(true)�Ǿ� ������..
			{
				Gun* gun = (Gun*)find(name[i]);

				if (gun != nullptr)
				{
					gun->onFire();
				}
			}
		}

		gunFireTimer = 0;
		gunFireIndex++;  //�ǹ迭��..�߻��ε��� ����

		if (gunFireIndex >= MAX_GUN_FIRE)
		{
			gunFireIndex = 0;  //�ǹ迭��..ó������ �ٽ� �߻� ���Ͻ���
		}
	}
}

void Boss::shellFire()
{
	//���� �߻��ϱ�
	cannonFireTimer = cannonFireTimer + Time::deltaTime;

	if (cannonFireTimer >= cannonFireDelay)
	{
		//�ڽĴ��� ã��
		string name[2] = { "����1", "����2" };

		for (int i = 0; i < 2; i++)
		{
			if (cannonFire[i][cannonFireIndex] == true)
			{
				Cannon* cannon = (Cannon*)find(name[i]);

				if (cannon != nullptr)
				{
					cannon->onFire();
				}
			}
		}

		cannonFireTimer = 0;
		cannonFireIndex++;

		if (cannonFireIndex >= MAX_CANNON_FIRE)
		{
			cannonFireIndex = 0;
		}
	}
}

void Boss::onChildDestroyed()
{
	childCount++;

	cout << "�Ҹ�� �ڽİ�ü ���� " << childCount <<  endl;

	//if (childCount == 25)
	if (childCount == 25)
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