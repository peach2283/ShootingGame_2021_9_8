#include "framework.h"
//C/C++���� �����ϴ� ������(M_PI) ����ϱ�
#define _USE_MATH_DEFINES
#include <math.h>

EnemyShell::EnemyShell(float angle, float px, float py) : Sprite("������ź","", true, px, py)
{
	this->speed = 100;
	this->angle = angle;

	this->lifeTime = 2.5;
}

EnemyShell::~EnemyShell()
{}

void EnemyShell::start()
{
	setImage("Asset/�Ѿ�2.bmp");
}

void EnemyShell::update()
{
	///�̵��ϱ�//
	//��������(unit vector / normal vector)//
	float nx = 1;
	float ny = 0;

	//ȸ�� ���� (���� ==> ���� ��ȯ)
	float theta = angle / 180.0f * M_PI; //���Ⱥ�ȯ
	
	//ȸ���� ��..speed�� �̵��� ��ǥ
	float x = speed * Time::deltaTime * cos(theta);
	float y = speed * Time::deltaTime * sin(theta);

	//ȸ���� ��������.�̵� ��Ű��
	translate(x, y);

	//������ Ÿ��
	lifeTime = lifeTime - Time::deltaTime;
	
	if (lifeTime <= 0)
	{
		destroy(this);
	}
}