#pragma once

#define ENEMY_MAX 20

class GameManager
{
private:
	static int  enemyCount;
	
	static bool dropLaserItem[ENEMY_MAX];
	static bool dropBombItem [ENEMY_MAX];

	static int   playerCount; //플레이어 카운트
	static float playerHp;    //플레이어 체력

	static bool bossDead;    //true - 보스가 죽음, false- 보스가 죽지 않음

	static bool isPause;     //true(일시중지), false(정상동작)

	static int bombCount;    //폭탄 카운트

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

	//플레이어 체력 감소하기
	static void applyDamage(float damage);

	//플레이어 체력 가져오기
	static float getPlayerHp();

	//플레이어 카운트 가져오기
	static int getPlayerCount();

	//폰탄 카운트 감소/증가/ 가져오기
	static void addBomb();  //폰탄증가
	static void subBmob();  //폰탄감수
	static int  getBombCount(); //폰타카운트 가져오기

	//보스데드 공유 변수..게터/세터
	static bool getBossDead();
	static void setBossDead();

	//일시중지 변수(isPause)게터/세터
	static bool getPause();
	static void setPause(bool pause);

	//게임매니저..데이타..리셋하기//
	static void reset();
};