#include "framework.h"

LaserItem::LaserItem(float px, float py)
		  :Sprite("레이저아이템", "", true, px, py)
{
	this->speed    = 50;
	this->lifeTime = 3;
}

LaserItem::~LaserItem()
{}

void LaserItem::start()
{
	setImage("Asset/총알아이템.bmp");
	addBoxCollider2D(0, 0, 22, 80);
}

void LaserItem::update()
{
	//이동하기
	float dist = speed * Time::deltaTime;
	translate(0, dist);

	//라이프타임
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		destroy(this);
	}
}

void LaserItem::onTriggerStay(GameObject* other)
{}