#pragma once

#include "Sprite.h"

class EnemyShell : public Sprite
{
private:
	float speed;
public:
	EnemyShell(float px, float py);
	~EnemyShell();

	void start();
	void update();
};