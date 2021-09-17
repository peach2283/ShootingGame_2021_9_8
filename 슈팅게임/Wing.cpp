#include "framework.h"

Wing::Wing(int imgX, int imgY, int imgW, int imgH,  float px, float py) 
	 : Wing(imgX, imgY, imgW, imgH, 0, 0, imgW, imgH, px, py)
{
}

Wing::Wing(int imgX, int imgY, int imgW, int imgH, float colX, float colY, float colW, float colH, float px, float py)
	: Sprite("","", true, px, py)
{
	this->imgX = imgX;
	this->imgY = imgY;
	this->imgW = imgW;
	this->imgH = imgH;

	this->colX = colX;
	this->colY = colY;
	this->colW = colW;
	this->colH = colH;

	this->hp = 100;
}

Wing::~Wing()
{}

void Wing::start()
{
	setImage("Asset/보스.bmp", imgX, imgY, imgW, imgH);
	addBoxCollider2D(colX, colY, colW, colH);
}

void Wing::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "플레이어레이저")
	{
		//플레이어 레이저..폭발효과//
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new PlayerLaserExp(ex - 15, ey - 15), 1);

		//플레이어 레이저..제거하기//
		destroy(other);

		//체력 감소 및 애니메이션 변경
		hp = hp - 10;

		if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "플레이어폭탄폭발")
	{
		explode();
	}
}

void Wing::explode()
{
	//자식폭발//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 50, py - 40), 1);

	//자식객체제거
	destroy(this);

	//부모 보스객체에...제거되었음을 알려줌
	Boss* boss = (Boss*)getParent();
	boss->onChildDestroyed();
}