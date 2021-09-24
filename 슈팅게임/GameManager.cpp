#include "framework.h"

int  GameManager::enemyCount			   = 0;

bool GameManager::dropLaserItem[ENEMY_MAX] = { false, false, false, false, false,    
											   false, false, false, false, true,

											   false, false, true, false, false,
											   false, false, true, true , true };

bool GameManager::dropBombItem[ENEMY_MAX] =  { false, false, false, false, true,
											   false, false, false, false, true,

											   false, false, false, false, true,
											   false, false, false, false, true };

int GameManager::playerCount = 3;

bool GameManager::bossDead   = false;

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

bool GameManager::doDropBombItem(int num)
{
	return dropBombItem[num];
}

int GameManager::getEnemyMax()
{
	return ENEMY_MAX;
}

void GameManager::playerSpawn(float px, float py)
{
	if (playerCount > 0)
	{
		ObjectManager::instantiate(new Player(px, py), 1);
		playerCount--;
	}
	else {
		
		//게임오버 UI 생성하기//
		ObjectManager::instantiate(new GameOver(30, 250), UI_LAYER);
	}
}

bool GameManager::getBossDead()
{
	return bossDead;
}

void GameManager::setBossDead()
{
	bossDead = true;  //보스가 죽었음을...공유 변수에..표시
}