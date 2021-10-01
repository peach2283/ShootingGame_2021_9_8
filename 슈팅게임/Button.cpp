#include "framework.h"

Button::Button(float px, float py) : Sprite("","", true, px, py)
{
	this->state = State::normal;
}

Button::~Button()
{}

void Button::start()
{
	//��ư �̹��� �ε��ϱ�//
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
				state = State::pressed; //�������·�..����
			}
		}
		break;

		case State::pressed:
		{
			if (Input::getMouseButtonUp(0) == true && isMouseInImageRect() == true)
			{											
				onClick();  //Ŭ�� �����Լ�..����

				translate(0, -1);
				state = State::normal; //����(����)���·�..����
			}

			//���콺��..�̹��� �簢�� ����������..�̵��ߴ��� �˻�
			if (isMouseInImageRect() != true)
			{
				translate(0, -1);
				state = State::normal; //����(����)���·�..����
			}
		}
		break;
	}
}

bool Button::isMouseInImageRect()
{
	//���콺 ��ǥ
	float mx = Input::mousePosition.x;
	float my = Input::mousePosition.y;

	//�̹��� ũ�� ���ϱ�
	int width, height;
	getSize(width, height);

	//�̹��� �簢�� ��ǥ
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
