#include "framework.h"

PlayerBomb::PlayerBomb(float px, float py)
		   :Animation("","",true, px, py)
{
	this->speed = 150;
}

PlayerBomb::~PlayerBomb()
{}

void PlayerBomb::start()
{
	for (int i = 0; i < 8; i++)
	{
		addImage("Asset/ÆÒÅÒÆøÅº2.bmp", i * 34, 0, 32, 32, 0);
	}

	//¾Ö´Ï¸ÞÀÌ¼Ç ¼Óµµ//
	setImageDelay(0.1);
}

void PlayerBomb::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);
}

void PlayerBomb::onAnimationEnd()
{
	destroy(this);
}