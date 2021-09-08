#pragma once

#include "Animation.h"

class Enemy : public Animation
{
	enum class State { moveDown = 0, moveLeft = 1, moveRight = 2, fall = 3 };

private:
	float speed;
	float fallSpeed;

	State state; //���º���

	float fireTimer;
	float fireDelay;

	float hp;
	float lifeTime; //�߶����� ������Ÿ��

public:
	Enemy(float px, float py);
	~Enemy();

	void start();
	void update();

	//�浹 �̺�Ʈ ó�� ... �������̵�//
	void onTriggerStay(GameObject* other);
};