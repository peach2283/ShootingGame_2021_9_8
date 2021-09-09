#pragma once

#include "GameObject.h"

class EnemySpawner : public GameObject
{
private:

	float spawnTimer;
	float spawnDelay;

	int maxSpawn;  //���� �ִ� ����Ƚ��

public:
	EnemySpawner(float px, float py);
	~EnemySpawner();

	void start();
	void update();

	//������..��ġ ǥ�� ����� �׸���//
	void onDrawGizmos();
};
