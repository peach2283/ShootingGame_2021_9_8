#include "framework.h"

Player::Player(float px, float py) : GameObject("�÷��̾�","�÷��̾�", true, px, py)
{	
	this->speed = 200; //�÷��̾� �̵� �ӷ�

	this->fireTimer = 0;   //�߻�Ÿ�̸�
	this->fireDelay = 0.2; //�߻���ð�

	this->index = 3;

	this->imageTimer = 0;
	this->imageDelay = 0.1; 

	this->state       = State::moveUp;
	this->shieldTimer = 3;

	this->laserCount = 0;
	this->bombCount  = 3;
}

Player::~Player()
{
	for (int i = 0; i < 7; i++)
	{
		delete[] image[i].argb;
	}
}

void Player::start()
{
	//�÷��̾� �̹����� ..�ε��ϱ�//
	Bitmap::readBMP("Asset/�����̵�2.bmp", 64 * 0, 82, 62, 80, &image[0]);
	Bitmap::readBMP("Asset/�����̵�2.bmp", 64 * 1, 82, 62, 80, &image[1]);
	Bitmap::readBMP("Asset/�����̵�2.bmp", 64 * 2, 82, 62, 80, &image[2]);
	Bitmap::readBMP("Asset/�����̵�2.bmp", 64 * 3, 82, 62, 80, &image[3]);
	Bitmap::readBMP("Asset/�����̵�2.bmp", 64 * 4, 82, 62, 80, &image[4]);
	Bitmap::readBMP("Asset/�����̵�2.bmp", 64 * 5, 82, 62, 80, &image[5]);
	Bitmap::readBMP("Asset/�����̵�2.bmp", 64 * 6, 82, 62, 80, &image[6]);

	//�浹ü..�߰��ϱ�
	addBoxCollider2D(25,  8, 13, 64); //��� ����
	addBoxCollider2D( 9, 43, 44, 14); //��� ����

	//�ڽİ�ü..�߰��ϱ�//
	addChildObject( new Shield(-10, -10), 1);
}

void Player::update()
{
	switch (state)
	{
		case State::moveUp :
		{
			//����..�̵��ϱ�//
			float dist = speed * Time::deltaTime;
			translate(0, -dist);

			//���� �̵� ��...�÷��� ��ġ�� �Ǹ�..
			float py = getPy();

			if (py <= 650)
			{
				state = State::control;
			}			
		}
		break;

		case State::control:
		{
			move();		//�̵�
			fire();		//�߻�	
			shield();	//���к�Ȱ��ȭ			
		}

		break;
	}

	//������ �׾�����...üũ�ϱ�//
	/**
	if (GameManager::getBossDead() == true)
	{		
		//��ȯ�÷��̾�..������
		float px = getPx();
		float py = getPy();

		instantiate(new ReturningPlayer(px, py), 1);

		//�÷��̾ ����
		destroy(this);
	}
	**/
}

void Player::onBossDestroyed()
{
	//��ȯ�÷��̾�..������
	float px = getPx();
	float py = getPy();

	instantiate(new ReturningPlayer(px, py), 1);

	//�÷��̾ ����
	destroy(this);
}

void Player::draw()
{
	float px = getPx();
	float py = getPy();

	Bitmap::drawBMP(px, py, &image[index]);
}

void Player::shield()
{
	//���� ��Ȱ��ȭ �ð������ϱ�//
	shieldTimer = shieldTimer - Time::deltaTime;

	if (shieldTimer <= 0)
	{
		//���� �ڽĿ�����Ʈ ã��
		GameObject* o = find("����");

		if (o != nullptr)
		{
			o->setActive(false); //���м���
			///destroy(o);
		}
		else {
			cout << "���и� ã�� ����" << endl;
		}
	}
}

void Player::move()
{
	float dist = speed * Time::deltaTime;  //�̵��Ÿ� ����ϱ�

	if (Input::getKey("left") == true)
	{
		translate(-dist, 0);

		//�÷��̾ ���� ȭ�������..������ ���ϰ� �ϱ�//
		float px = getPx();

		if (px < -10)
		{
			setPx(-10);
		}

		//�÷��̾�..�̹��� �ε���..����//
		imageTimer = imageTimer + Time::deltaTime;

		if (imageTimer >= imageDelay)
		{
			index--;

			if (index < 0)
			{
				index = 0;
			}

			imageTimer = 0;
		}
	}

	if (Input::getKey("right") == true)
	{
		translate(dist, 0);

		//�÷��̾ ������ ȭ�������..������ ���ϰ� �ϱ�//
		float px = getPx();

		if (px > WIDTH - 54)
		{
			setPx(WIDTH - 54);
		}

		//�÷��̾�..�̹��� �ε���..����//
		imageTimer = imageTimer + Time::deltaTime;

		if (imageTimer >= imageDelay)
		{
			index++;

			if (index > 6)
			{
				index = 6;
			}

			imageTimer = 0;
		}
	}

	if (Input::getKey("left") != true && Input::getKey("right") != true)
	{
		index = 3;
	}

	if (Input::getKey("up") == true)
	{
		translate(0, -dist);

		//�÷��̾ ���� ȭ�������..������ ���ϰ� �ϱ�//
		float py = getPy();

		if (py < 0)
		{
			setPy(0);
		}
	}

	if (Input::getKey("down") == true)
	{
		translate(0, dist);

		//�÷��̾ �Ʒ��� ȭ�������..������ ���ϰ� �ϱ�//
		float py = getPy();

		if (py > HEIGHT - 80)
		{
			setPy(HEIGHT - 80);
		}
	}
}

void Player::fire()
{
	//������ ... �߻��ϱ�//
	if (Input::getKey("space") == true && GameManager::getPause() == false)
	{		
		//�߻�ð� �����ϱ�
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = getPx() + 28;
			float py = getPy() - 20;

			if (laserCount == 0)
			{
				//������ �ѹ� �߻�
				instantiate(new PlayerLaser(px, py), 0);
			}
			else if (laserCount == 1)
			{
				//������ �ι� �߻�
				instantiate(new PlayerLaser(px - 5, py), 0);
				instantiate(new PlayerLaser(px + 5, py), 0);
			}
			else if (laserCount == 2)
			{
				//������ ���� �߻�
				instantiate(new PlayerLaser(px - 8, py), 0);
				instantiate(new PlayerLaser(px, py - 10), 0);
				instantiate(new PlayerLaser(px + 8, py), 0);
			}

			fireTimer = 0; //Ÿ�̸� �����ϱ�
		}
	}

	//��ź...�߻��ϱ�//
	if (Input::getKeyDown("z") == true && GameManager::getPause() == false)
	{
		if (bombCount > 0)
		{
			float px = getPx();
			float py = getPy();

			instantiate(new PlayerBomb(px + 15, py), 0);
			
			//bombCount--; //��ź���� ���̱�
		}
		else {
			cout << "---�����ִ� ��ź�� �����ϴ�---" << endl;
		}

		cout << "��ź ���� " << bombCount << endl;
	}
}

void Player::onTriggerStay(GameObject* other)
{	
	string tag = other->getTag();

	if (tag == "����" || tag=="����")
	{
		explode();
	}
	else if (tag == "�����Ѿ�" || tag == "������ź")
	{
		//�÷��̾� ü�� ����
		GameManager::applyDamage(10);

		//���� �Ѿ����ϱ�
		destroy(other);

		//�Ѿ� ���� ȿ��
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new EnemyBulletExp(ex-10, ey), 1);

		//�÷��̾� ���� �� ����
		if (GameManager::getPlayerHp() <= 0)
		{
			explode();
		}
	}
	else if (tag == "������������")
	{
		if (laserCount < 2)
		{
			//�������߻簹�� �ø���//
			laserCount++;
		}

		//������������ ����//
		destroy(other);

	}
	else if (tag == "��ź������")
	{
		//��ź���� ����
		bombCount++;

		cout << "��ź ���� " << bombCount << endl;

		//��ź������ ����//
		destroy(other);
	}
}

void Player::explode()
{
	//�÷��̾� ���� �� ����//
	float px = getPx();
	float py = getPy();

	instantiate(new ShipExp(px - 20, py - 10), 1);  //�÷��̾� ���� ȿ��
	destroy(this);									//�÷��̾� ����

	//�÷��̾� �������ϱ�//
	GameManager::playerSpawn(240 - 40, HEIGHT + 50);
}