#include "framework.h"

int Enemy::Num = 0;

Enemy::Enemy(float px, float py) : Animation("����","",true, px, py)
{
	this->speed		= 50;
	this->fallSpeed = 200;

	this->state = State::moveDown;

	this->fireTimer = 0;
	this->fireDelay = 1;

	this->hp	   = 100;
	this->lifeTime = 5;
}

Enemy::~Enemy()
{}

void Enemy::start()
{
	/*************************[���ؾ��� �ִϸ��̼�******************/
	addImage("Asset/����.bmp", 1 + 200 * 0, 281, 190, 137, 0);
	addImage("Asset/����.bmp", 1 + 200 * 1, 281, 190, 137, 0);
	/**************************************************************/

	/*************************[�߰����� ���� �ִϸ��̼�**************/
	addImage("Asset/����.bmp", 1 + 200 * 0, 141, 190, 137, 1);
	addImage("Asset/����.bmp", 1 + 200 * 1, 141, 190, 137, 1);
	addImage("Asset/����.bmp", 1 + 200 * 2, 141, 190, 137, 1);
	addImage("Asset/����.bmp", 1 + 200 * 3, 141, 190, 137, 1);
	/***************************************************************/

	/************************[���� ���� �ִϸ��̼�]*******************/
	addImage("Asset/����.bmp", 1 + 200 * 0, 1, 190, 137, 2);
	addImage("Asset/����.bmp", 1 + 200 * 1, 1, 190, 137, 2);
	addImage("Asset/����.bmp", 1 + 200 * 2, 1, 190, 137, 2);
	addImage("Asset/����.bmp", 1 + 200 * 3, 1, 190, 137, 2);
	/***************************************************************/

	//�ִϸ��̼� Ŭ�� �����ϱ�//
	setClipId(0);

	//�浹ü..�߰��ϱ�//
	addBoxCollider2D(67, 10, 56, 13 );  //�������� 
	addBoxCollider2D(88, 23, 14, 114);  //��� ����
	addBoxCollider2D( 4, 91, 182,14 );  //��� ����

	//�¿��̵� ������ġ
	hMovePos = Random::Range(50, 150);

	//��ü��ȣ��������
	num = Num; //��ü������ȣ
	Num++;     //������ȣ ����
}

void Enemy::update()
{
	//���� �̵� ������Ʈ �ӽ�//
	/***********************/
	switch (state)
	{
		case State::moveDown:
		{
			float dist = speed * Time::deltaTime;
			translate(0, dist);

			int py = getPy();

			if (py >= hMovePos)
			{
				State dir[2] = {State::moveLeft, State::moveRight};
				state = dir[ Random::Range(0,1) ];
			}
		}
		break;

		case State::moveLeft:
		{
			float dist = speed * Time::deltaTime;
			translate(-dist, 0);

			int px = getPx();

			if (px <= 0)
			{
				state = State::moveRight;
			}

		}
		break;

		case State::moveRight:
		{
			float dist = speed * Time::deltaTime;
			translate(dist, 0);

			int px = getPx();

			if (px >= WIDTH - 190)
			{
				state = State::moveLeft;
			}
		}
		break;

		case State::fall:
		{
			//�߶��̵�//
			float dist = fallSpeed * Time::deltaTime;
			translate(0, dist);			

			//������ Ÿ��//
			lifeTime = lifeTime - Time::deltaTime;

			if (lifeTime <= 0)
			{
				destroy(this);					
			}
		}
		break;
	}
	/******************************/

	//���� �� �߻�//
	fireTimer = fireTimer + Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float px = getPx();
		float py = getPy();

		instantiate(new EnemyBullet(px+86, py+130), 0);

		fireTimer = 0;
	}
}

void Enemy::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�÷��̾����")
	{
		hp = hp - 10;
		
		//�÷��̾� ������..����ȿ��//
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new PlayerLaserExp(ex-15, ey-15), 1);

		//�÷��̾� ������..�����ϱ�//
		destroy(other);

		//���� ü�� ���
		//cout << "���� ü�� " << hp << endl;

		//ü�°��ҿ� ����..�ִϸ��̼� ���� �� ����//
		if (70 < hp && hp <= 100)
		{
			setClipId(0);
		}
		else if (40 < hp && hp <= 70)
		{
			setClipId(1);
		}
		else if (0 < hp && hp <= 40)
		{
			setClipId(2);
			state = State::fall;  //�߶����·�..����

		}else  if (hp <= 0)
		{
			float px = this->getPx();
			float py = this->getPy();

			instantiate(new ShipExp(px+30, py+20), 1); //��������ȿ��
			destroy(this);						       //��������

			//������������..��������(�迭)����ϱ�
			if (GameManager::doDropLaserItem(num) == true)
			{
				//������������ ����//
				instantiate(new LaserItem(px + 88, py + 50), 0);
			}

			//������������ ����Ȯ��
			/***********************
			int p = Random::Range(0, 32767);

			if (p < 32767/2)
			{
				//������������ ����//
				instantiate(new LaserItem(px + 88, py + 50), 0);
			}
			**************************/
		}
	}
	else if (tag == "����" || tag == "�÷��̾���ź����")
	{
		//���� ���� ȿ����..�ʿ��ϸ�...�̵��Ҽ� ����//

		//������������..��������(�迭)����ϱ�
		if (GameManager::doDropLaserItem(num) == true)
		{
			float px = this->getPx();
			float py = this->getPy();

			//������������ ����//
			instantiate(new LaserItem(px + 88, py + 50), 0);
		}
	}
}

void Enemy::onDestroy()
{
	GameManager::subEnemy();  //����ī��Ʈ ����
}