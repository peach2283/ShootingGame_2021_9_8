#include "framework.h"

DeadBoss::DeadBoss(float px, float py):Sprite("","",true, px, py)
{
	this->speed    = 150;
	this->lifeTime = 5;
}

DeadBoss::~DeadBoss()
{}

void DeadBoss::start()
{
	//폭발된 보스
	setImage("Asset/보스.bmp", 0, 613, 385, 182);
}

void DeadBoss::update()
{
	//이동(추락) 하기//
	float dist = speed * Time::deltaTime;
	translate(0, dist);

	//라이프타임(스테이지 클리어 타임)//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		//보스 객체 제거//
		destroy(this);
	}
}