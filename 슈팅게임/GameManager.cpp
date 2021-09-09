#include "framework.h"

int GameManager::enemyCount = 0;

void GameManager::addEnemy() //스폰에서..적기 카운트 증가
{
	enemyCount++;
}

void GameManager::subEnemy() //적기제거 에서..적기 카운트 감소
{
	enemyCount--;
}

int GameManager::getEnemyCount()
{
	return enemyCount;
}