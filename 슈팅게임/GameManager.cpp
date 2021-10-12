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

int   GameManager::playerCount = 3;
float GameManager::playerHp  = 100;

bool GameManager::bossDead  = false;
bool GameManager::isPause   = false;

int GameManager::bombCount = 3;

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

		playerHp  = 100;
		bombCount = 3;
	}
	else {
		
		//���ӿ��� UI �����ϱ�//
		ObjectManager::instantiate(new GameOver(30, 250), UI_LAYER-1);
	}
}

void GameManager::applyDamage(float damage)
{
	playerHp = playerHp - damage;
}

float GameManager::getPlayerHp()
{
	return playerHp;
}

int GameManager::getPlayerCount()
{
	return playerCount;
}

bool GameManager::getBossDead()
{
	return bossDead;
}

void GameManager::addBomb()
{
	if (bombCount < 5)  //��ź ������ �ִ� 5�� ���� 
	{
		bombCount++;
	}
}

void GameManager::subBomb()
{
	bombCount--;
}

int GameManager::getBombCount()
{
	return bombCount;
}

void GameManager::setBossDead()
{
	bossDead = true;  //������ �׾�����...���� ������..ǥ��
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
	//Ÿ�̸� ����//
	Time::timeScale = 1.0f;

	//���Ӱ��� ����Ÿ ����//
	enemyCount	= 0;

	playerCount = 3;
	playerHp    = 100;

	bossDead = false;
	isPause  = false;	

	bombCount = 3;
}