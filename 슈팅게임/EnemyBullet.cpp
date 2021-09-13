#include "framework.h"

EnemyBullet::EnemyBullet(float px, float py) : Sprite("�����Ѿ�","",true, px, py)
{
	this->speed	   = 150;
	this->lifeTime = 10;
}

EnemyBullet::~EnemyBullet()
{}

void EnemyBullet::start()
{
	setImage("Asset/�Ѿ�1.bmp");

	//�浹ü �߰��ϱ�//
	addBoxCollider2D(0, 0, 17, 15);
}

void EnemyBullet::update()
{
	//�̵�//
	float dist = speed * Time::deltaTime;
	translate(0, dist);

	//������Ÿ��//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		destroy(this);
	}
}