#include "framework.h"

Button::Button(float px, float py) : Sprite("","", true, px, py)
{}

Button::~Button()
{}

void Button::start()
{
	//��ư �̹��� �ε��ϱ�//
	setImage("Asset/UI/item.bmp");
}

void Button::update()
{
	if (Input::getKeyDown("lbutton") == true)
	{
		cout << "���콺 ���� ��ư ����" << endl;
	}
}