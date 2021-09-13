#include "framework.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("적기총알","",true, px, py)
{
	this->speed	   = 150;
	this->lifeTime = 10;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::start()
{
	setImage("Asset/총알1.bmp");

	//충돌체 추가하기//
	addBoxCollider2D(0, 0, 17, 15);
}

void EnemyBullet::update()
{
	//이동//
	float dist = speed * Time::deltaTime;
	translate(0, dist);

	//라이프타임//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		destroy(this);
	}
}