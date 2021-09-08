#include "framework.h"

PlayerLaser::PlayerLaser(float px, float py) :Sprite("�÷��̾����", "", true, px, py)
{	
	this->speed    = 250;
	this->lifeTime = 10;
}

PlayerLaser::~PlayerLaser()
{}

void PlayerLaser::start()
{
	setImage("Asset/������.bmp");

	//�浹ü �߰��ϱ�//
	addBoxCollider2D(0, 0, 6, 33);
}

void PlayerLaser::update()
{
	//�̵��ϱ�//
	float dist = speed * Time::deltaTime;
	translate(0, -dist);

	//������Ÿ�� ����//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		destroy(this);
	}
}
