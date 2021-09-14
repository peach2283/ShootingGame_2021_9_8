#pragma once

#include "Sprite.h"

class BombItem : public Sprite
{
	enum class State{show=0, hide=1};

private:

	//������(blink) Ÿ�̸�//
	float blinkTimer;
	//float blinkDelay;

	float showDelay;
	float hideDelay;

	//���º���//
	State state;

	//������ Ÿ��
	float lifeTime;

public:
	BombItem(float px, float py);
	~BombItem();

	void start();
	void update();
};