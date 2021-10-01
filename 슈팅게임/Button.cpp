#include "framework.h"

Button::Button(float px, float py) : Sprite("","", true, px, py)
{
	this->state = State::normal;
}

Button::~Button()
{}

void Button::start()
{
	//버튼 이미지 로드하기//
	setImage("Asset/UI/item.bmp");
}

void Button::update()
{
	switch (state)
	{
		case State::normal:
		{
			if (Input::getMouseButtonDown(0) == true && isMouseInImageRect() == true)
			{			
				translate(0, 1);
				state = State::pressed; //눌림상태로..전이
			}
		}
		break;

		case State::pressed:
		{
			if (Input::getMouseButtonUp(0) == true && isMouseInImageRect() == true)
			{											
				onClick();  //클릭 가상함수..실행

				translate(0, -1);
				state = State::normal; //놓임(정상)상태로..전이
			}

			//마우스가..이미지 사각형 영역밖으로..이동했는지 검사
			if (isMouseInImageRect() != true)
			{
				translate(0, -1);
				state = State::normal; //놓임(정상)상태로..전이
			}
		}
		break;
	}
}

bool Button::isMouseInImageRect()
{
	//마우스 좌표
	float mx = Input::mousePosition.x;
	float my = Input::mousePosition.y;

	//이미지 크기 구하기
	int width, height;
	getSize(width, height);

	//이미지 사각형 좌표
	float x0 = getPx();
	float y0 = getPy();

	float x1 = x0 + width;
	float y1 = y0 + height;

	if (x0 <= mx && mx <= x1 && y0 <= my && my <= y1)
	{
		return true;
	}
	else {
		return false;
	}
}

void Button::onClick()
{}
