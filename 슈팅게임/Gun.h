#pragma once

#include "Sprite.h"

class Gun : public Sprite
{
private:
	float hp;

	//float fireTimer;
	//float fireDelay;

public:
	Gun(string name, float px, float py);
	~Gun();

	void start();
	void update();

	//보스(부모객체)에서..발생시키는 발사 이벤트//
	void onFire();

	void onTriggerStay(GameObject* other);
	void explode();
};