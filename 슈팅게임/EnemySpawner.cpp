#include "framework.h"

EnemySpawner::EnemySpawner(float px, float py)
			:GameObject("", "", true, px, py)
{
	this->spawnTimer = 0;
	this->spawnDelay = 1;
}

EnemySpawner::~EnemySpawner()
{}

void EnemySpawner::start()
{}

void EnemySpawner::update()
{
	//�����ð� ����
	spawnTimer = spawnTimer + Time::deltaTime;

	if (spawnTimer >= spawnDelay)
	{
		//���� �����ϱ�//
		float px = getPx();
		float py = getPy();

		instantiate(new Enemy(px, py), 1);

		spawnTimer = 0;
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