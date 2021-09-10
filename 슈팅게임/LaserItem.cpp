#include "framework.h"

LaserItem::LaserItem(float px, float py)
		  :Sprite("레이저아이템", "", true, px, py)
{}

LaserItem::~LaserItem()
{}

void LaserItem::start()
{
	setImage("Asset/총알아이템.bmp");
	addBoxCollider2D(0, 0, 22, 80);
}

void LaserItem::onTriggerStay(GameObject* other)
{}