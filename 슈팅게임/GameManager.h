#pragma once

class GameManager
{
private:
	static int enemyCount;
public:

	//적기카운트..증가 감소 함수//
	static void addEnemy(); //스폰에서..적기 카운트 증가
	static void subEnemy(); //적기제거 에서..적기 카운트 감소

	//적기카운트 게터//
	static int getEnemyCount(); //적기카운트값 가져오기
};