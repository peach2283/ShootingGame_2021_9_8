#include "framework.h"

LaserItem::LaserItem(float px, float py)
		  :Sprite("������������", "", true, px, py)
{
	this->speed    = 50;
	this->lifeTime = 3;
}

LaserItem::~LaserItem()
{}

void LaserItem::start()
{
	setImage("Asset/�Ѿ˾�����.bmp");
	addBoxCollider2D(0, 0, 22, 80);
}

void LaserItem::update()
{
	//�̵��ϱ�
	float dist = speed * Time::deltaTime;
	translate(0, dist);

	//������Ÿ��
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		destroy(this);
	}
}

void LaserItem::onTriggerStay(GameObject* other)
{}