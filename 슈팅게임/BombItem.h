#pragma once

#include "Sprite.h"

class BombItem : public Sprite
{
	enum class State{show=0, hide=1};

private:

	//깜빡임(blink) 타이머//
	float blinkTimer;
	//float blinkDelay;

	float showDelay;
	float hideDelay;

	//상태변수//
	State state;

	//라이프 타임
	float lifeTime;

public:
	BombItem(float px, float py);
	~BombItem();

	void start();
	void update();
};