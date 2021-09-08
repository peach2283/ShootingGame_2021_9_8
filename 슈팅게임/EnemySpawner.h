#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:

	float spawnTimer;
	float spawnDelay;

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void start();
	void update();

	//스포너..위치 표시 기즈모 그리기//
	void onDrawGizmos();
};
