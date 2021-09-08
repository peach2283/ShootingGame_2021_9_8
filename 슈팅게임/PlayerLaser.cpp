#include "framework.h"

PlayerLaser::PlayerLaser(float px, float py) :Sprite("플레이어레이저", "", true, px, py)
{	
	this->speed    = 250;
	this->lifeTime = 10;
}

PlayerLaser::~PlayerLaser()
{}

void PlayerLaser::start()
{
	setImage("Asset/레이저.bmp");

	//충돌체 추가하기//
	addBoxCollider2D(0, 0, 6, 33);
}

void PlayerLaser::update()
{
	//이동하기//
	float dist = speed * Time::deltaTime;
	translate(0, -dist);

	//라이프타임 측정//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		destroy(this);
	}
}
