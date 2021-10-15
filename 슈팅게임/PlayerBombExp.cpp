#include "framework.h"

PlayerBombExp::PlayerBombExp(float px, float py)
			  :Animation("플레이어폭탄폭발","", true, px, py)
{}

PlayerBombExp::~PlayerBombExp()
{}

void PlayerBombExp::start()
{
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			addImage("Asset/폭탄폭발.bmp", col * 130, row * 130, 128, 128, 0);
		}
	}

	//충돌체 추가하기//
	addBoxCollider2D(19, 19, 90, 90);
}

void PlayerBombExp::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "적기총알" || tag == "적기포탄")
	{
		destroy(other); //총알객체 제거
	}
	else if (tag == "적기")
	{
		float px = other->getPx();
		float py = other->getPy();

		instantiate(new ShipExp(px + 30, py + 20), 1); //적기폭발효과
		destroy(other);						           //적기제거

		//점수 올리기//
		GameManager::addScore(10);
	}
}

void PlayerBombExp::onAnimationEnd()
{
	destroy(this);
}