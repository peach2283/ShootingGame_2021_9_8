#include "framework.h"

int  GameManager::enemyCount			   = 0;
bool GameManager::dropLaserItem[ENEMY_MAX] = { false, false, false, false, false,    
											   false, false, false, false, true,

											   false, false, true, false, false,
											   false, false, true, true , true };

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

bool GameManager::doDropLaserItem(int num)
{
	return dropLaserItem[num];
}

int GameManager::getEnemyMax()
{
	return ENEMY_MAX;
}