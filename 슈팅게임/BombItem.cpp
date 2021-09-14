#include "framework.h"

BombItem::BombItem(float px, float py)
		:Sprite("��ź������", "", true, px, py)
{
	this->blinkTimer = 0;
	//this->blinkDelay = 0.3;

	this->showDelay = 0.5;
	this->hideDelay = 0.1;

	this->state = State::show;

	this->lifeTime = 5;
}

BombItem::~BombItem()
{}

void BombItem::start()
{
	setImage("Asset/��ź������.bmp");
	addBoxCollider2D(0, 0, 22, 40);	
}

void BombItem::update()
{
	//Blink ������Ʈ �ӽ�//
	switch (state)
	{
		case State::show:
		{
			blinkTimer = blinkTimer + Time::deltaTime;

			if (blinkTimer >= showDelay)
			{
				setEnabled(false);

				state = State::hide;
				blinkTimer = 0;
			}
		}
		break;

		case State::hide:
		{
			blinkTimer = blinkTimer + Time::deltaTime;

			if (blinkTimer >= hideDelay)
			{
				setEnabled(true);

				state = State::show;
				blinkTimer = 0;
			}
		}
		break;
	}

	//������Ÿ��
	lifeTime = lifeTime - Time::deltaTime;

	if (lifeTime <= 0)
	{
		destroy(this);
	}

#if 0
	blinkTimer = blinkTimer + Time::deltaTime;

	if (blinkTimer >= blinkDelay)
	{
		/***********************
		if (getEnabled() == true)
		{
			setEnabled(false);
		}
		else {
			setEnabled(true);
		}
		***********************/

		/*setEnabled( (getEnabled() == true) ? false : true );*/

		setEnabled( !getEnabled() );

		blinkTimer = 0;
	}
#endif	
}