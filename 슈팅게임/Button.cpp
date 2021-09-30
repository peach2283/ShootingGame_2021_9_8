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
	//if(Input::getMouseButtonDown(0)==true)
	//{
	//	cout << "���콺 ���ʹ�ư�� ����" << endl;
	//}

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
		cout << "���콺��..��ư �̹��� �簢�� �ȿ� ����" << endl;
	}

}