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

bool GameManager::bossDead  = false;
bool GameManager::isPause   = false;

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

bool GameManager::getPause()
{
	return isPause;
}

void GameManager::setPause(bool pause)
{
	isPause = pause;
}

void GameManager::reset()
{
	//타이머 리셋//
	Time::timeScale = 1.0f;

	//게임관리 데이타 리셋//
	enemyCount	= 0;
	playerCount = 3;
	bossDead = false;
	isPause  = false;
}