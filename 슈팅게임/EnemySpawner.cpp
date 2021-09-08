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
	//스폰시간 측정
	spawnTimer = spawnTimer + Time::deltaTime;

	if (spawnTimer >= spawnDelay)
	{
		//적기 스폰하기//
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

	//십자표시 출력하기//
	drawLine(px - 30, py,    px + 30, py   ,  255, 0, 0);
	drawLine(px     , py-30, px		, py+30,  255, 0, 0);
}