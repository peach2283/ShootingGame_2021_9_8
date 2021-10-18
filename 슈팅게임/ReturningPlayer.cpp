#include "framework.h"

ReturningPlayer::ReturningPlayer(float px, float py) : Animation("","", true, px, py)
{
	this->speed = 150;
}

ReturningPlayer::~ReturningPlayer()
{}

void ReturningPlayer::start()
{
	for (int col = 0; col < 11; col++)
	{
		addImage("Asset/팬텀귀환.bmp", 64*col, 0, 62, 240, 0);
	}
}

void ReturningPlayer::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);

	//기지 귀환완료 / 스테이지 클리어 하기//
	if (getPy() < 0)
	{
		//귀환 플레이어 제거
		destroy(this);

		//스테이지 클리어 : 엔딩씬 전환//
		SceneManager::loadScene("EndingScene");
	}
}