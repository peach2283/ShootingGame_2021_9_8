#include "framework.h"

LaserItem::LaserItem(float px, float py)
		  :Sprite("������������", "", true, px, py)
{}

LaserItem::~LaserItem()
{}

void LaserItem::start()
{
	setImage("Asset/�Ѿ˾�����.bmp");
	addBoxCollider2D(0, 0, 22, 80);
}

void LaserItem::onTriggerStay(GameObject* other)
{}