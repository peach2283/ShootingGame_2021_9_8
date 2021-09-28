#include "framework.h"
//C/C++에서 제공하는 원주율(M_PI) 사용하기
#define _USE_MATH_DEFINES
#include <math.h>

EnemyShell::EnemyShell(float angle, float px, float py) : Sprite("적기포탄","", true, px, py)
{
	this->speed = 100;
	this->angle = angle;

	this->lifeTime = 2.5;
}

EnemyShell::~EnemyShell()
{}

void EnemyShell::start()
{
	setImage("Asset/총알2.bmp");
}

void EnemyShell::update()
{
	///이동하기//
	//단위벡터(unit vector / normal vector)//
	float nx = 1;
	float ny = 0;

	//회전 각도 (각도 ==> 라디안 변환)
	float theta = angle / 180.0f * M_PI; //라디안변환
	
	//회전전 후..speed로 이동한 좌표
	float x = speed * Time::deltaTime * cos(theta);
	float y = speed * Time::deltaTime * sin(theta);

	//회전된 방향으로.이동 시키기
	translate(x, y);

	//라이프 타임
	lifeTime = lifeTime - Time::deltaTime;
	
	if (lifeTime <= 0)
	{
		destroy(this);
	}
}