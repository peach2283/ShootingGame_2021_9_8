#include "framework.h"

int GameManager::enemyCount = 0;

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