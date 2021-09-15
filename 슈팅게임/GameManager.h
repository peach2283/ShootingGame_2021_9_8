#pragma once

#define ENEMY_MAX 20

class GameManager
{
private:
	static int  enemyCount;
	
	static bool dropLaserItem[ENEMY_MAX];
	static bool dropBombItem [ENEMY_MAX];

	static int playerCount;

public:

	//적기카운트..증가 감소 함수//
	static void addEnemy(); //스폰에서..적기 카운트 증가
	static void subEnemy(); //적기제거 에서..적기 카운트 감소

	//적기카운트 게터//
	static int getEnemyCount(); //적기카운트값 가져오기

	//적기 최대 스폰 갯수
	static int getEnemyMax();

	//적기가 레이저아이템/폭탄아이템 생성여부 가져오기//
	static bool doDropLaserItem(int num);
	static bool doDropBombItem (int num);

	//플레이어 스폰하기
	static void playerSpawn(float px, float py);
};