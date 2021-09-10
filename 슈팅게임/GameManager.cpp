#include "framework.h"

int  GameManager::enemyCount			   = 0;
bool GameManager::dropLaserItem[ENEMY_MAX] = { false, false, false, false, false,    
											   false, false, false, false, true,

											   false, false, true, false, false,
											   false, false, true, true , true };

void GameManager::addEnemy() //��������..���� ī��Ʈ ����
{
	enemyCount++;
}

void GameManager::subEnemy() //�������� ����..���� ī��Ʈ ����
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