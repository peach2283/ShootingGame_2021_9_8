#include "framework.h"

EnemySpawner::EnemySpawner(float px, float py)
			:GameObject("", "", true, px, py)
{
	this->spawnTimer = 0;
	this->spawnDelay = 2;

	this->maxSpawn = GameManager::getEnemyMax();
}

EnemySpawner::~EnemySpawner()
{}

void EnemySpawner::start()
{}

void EnemySpawner::update()
{
	if (maxSpawn > 0)  //���⽺���ϱ�
	{
		//�����ð� ����
		spawnTimer = spawnTimer + Time::deltaTime;

		if (spawnTimer >= spawnDelay)
		{
			if (GameManager::getEnemyCount() < 2)
			{
				//���� �����ϱ�//
				float px = getPx();
				float py = getPy();

				//������ġ ������
				int r = Random::Range(0, 2); //0,1,2

				//���� x ��ġ �迭
				float xs[3] = { -150, 0, +150 };

				//instantiate(new Enemy(px - 95 - 150, py - 137), 1);  //���⽺�� (����)
				//instantiate(new Enemy(px - 95, py - 137),  1);       //���⽺�� (���)
				//instantiate(new Enemy(px - 95 + 150, py - 137), 1);  //���⽺�� (���)

				instantiate(new Enemy(px - 95 + xs[r], py - 137), 1);
				maxSpawn--;               //�ִ뽺�� Ƚ�� ����    

				GameManager::addEnemy();  //���� ī��Ʈ ����


				spawnTimer = 0;
			}
		}
	}
	else { //���� �����ϱ�

		instantiate(new Boss(0, 0), 0);
		cout << "���� �����ϱ�" << endl;

		//���� ������..�����ϱ�//
		destroy(this);
	}
}

void EnemySpawner::onDrawGizmos()
{
	float px = getPx();
	float py = getPy();

	//����ǥ�� ����ϱ�//
	drawLine(px - 30, py,    px + 30, py   ,  255, 0, 0);
	drawLine(px     , py-30, px		, py+30,  255, 0, 0);
}