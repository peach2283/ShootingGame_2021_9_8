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
	//���ߵ� ����
	setImage("Asset/����.bmp", 0, 613, 385, 182);
}

void DeadBoss::update()
{
	//�̵�(�߶�) �ϱ�//
	float dist = speed * Time::deltaTime;
	translate(0, dist);

	//������Ÿ��(�������� Ŭ���� Ÿ��)//
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		//���� ��ü ����//
		destroy(this);
	}
}