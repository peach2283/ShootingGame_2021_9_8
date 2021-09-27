#include "framework.h"
//C/C++���� �����ϴ� ������(M_PI) ����ϱ�
#define _USE_MATH_DEFINES
#include <math.h>

EnemyShell::EnemyShell(float px, float py) : Sprite("������ź","", true, px, py)
{
	this->speed = 100;
}

EnemyShell::~EnemyShell()
{}

void EnemyShell::start()
{
	setImage("Asset/�Ѿ�2.bmp");
}

void EnemyShell::update()
{
	//��������(unit vector / normal vector)//
	float nx = 1;
	float ny = 0;

	//ȸ�� ���� (���� ==> ���� ��ȯ)
	float angle = 20;                    //20�� ȸ��
	float theta = angle / 180.0f * M_PI; //���Ⱥ�ȯ
	 
	//float dist = speed * Time::deltaTime;
	//translate(0, dist);
}