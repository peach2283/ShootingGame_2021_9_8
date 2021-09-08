#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { moveDown = 0, moveLeft = 1, moveRight = 2, fall = 3 };

private:
	float speed;
	float fallSpeed;

	State state; //상태변수

	float fireTimer;
	float fireDelay;

	float hp;
	float lifeTime; //추락상태 라이프타임

public:
	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();

	//충돌 이벤트 처리 ... 오버라이딩//
	void onTriggerStay(GameObject* other);
};