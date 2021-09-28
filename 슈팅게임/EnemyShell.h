#pragma once

#include "Sprite.h"

class EnemyShell : public Sprite
{
private:
	float speed;
	float angle;

	float lifeTime;

public:
	EnemyShell(float angle, float px, float py);
	~EnemyShell();

	void start();
	void update();
};