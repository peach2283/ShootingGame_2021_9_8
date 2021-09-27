#include "framework.h"
//C/C++에서 제공하는 원주율(M_PI) 사용하기
#define _USE_MATH_DEFINES
#include <math.h>

EnemyShell::EnemyShell(float px, float py) : Sprite("적기포탄","", true, px, py)
{
	this->speed = 100;
}

EnemyShell::~EnemyShell()
{}

void EnemyShell::start()
{
	setImage("Asset/총알2.bmp");
}

void EnemyShell::update()
{
	//단위벡터(unit vector / normal vector)//
	float nx = 1;
	float ny = 0;

	//회전 각도 (각도 ==> 라디안 변환)
	float angle = 20;                    //20도 회전
	float theta = angle / 180.0f * M_PI; //라디안변환
	 
	//float dist = speed * Time::deltaTime;
	//translate(0, dist);
}