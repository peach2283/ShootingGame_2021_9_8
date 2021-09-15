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
	if (maxSpawn > 0)  //적기스폰하기
	{
		//스폰시간 측정
		spawnTimer = spawnTimer + Time::deltaTime;

		if (spawnTimer >= spawnDelay)
		{
			if (GameManager::getEnemyCount() < 2)
			{
				//적기 스폰하기//
				float px = getPx();
				float py = getPy();

				//스폰위치 랜덤값
				int r = Random::Range(0, 2); //0,1,2

				//스폰 x 위치 배열
				float xs[3] = { -150, 0, +150 };

				//instantiate(new Enemy(px - 95 - 150, py - 137), 1);  //적기스폰 (왼쪽)
				//instantiate(new Enemy(px - 95, py - 137),  1);       //적기스폰 (가운데)
				//instantiate(new Enemy(px - 95 + 150, py - 137), 1);  //적기스폰 (가운데)

				instantiate(new Enemy(px - 95 + xs[r], py - 137), 1);
				maxSpawn--;               //최대스폰 횟수 감소    

				GameManager::addEnemy();  //적기 카운트 증가


				spawnTimer = 0;
			}
		}
	}
	else { //보스 스폰하기

		instantiate(new Boss(0, 0), 0);
		cout << "보스 스폰하기" << endl;

		//적기 스포너..제거하기//
		destroy(this);
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