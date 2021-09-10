#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { moveDown = 0, moveLeft = 1, moveRight = 2, fall = 3 };

private:
	//적기 스폰번호
	static int Num;  //공유
	int num;         //개별객체의 번호

	float speed;
	float fallSpeed;

	State state; //상태변수

	float fireTimer;
	float fireDelay;

	float hp;
	float lifeTime; //추락상태 라이프타임

	float hMovePos; //좌우이동 시작 위치

public:
	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();

	//충돌 이벤트 처리 ... 오버라이딩//
	void onTriggerStay(GameObject* other);

	//제거 이벤트 처리...오버라이디//
	void onDestroy();
};