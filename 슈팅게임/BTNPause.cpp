#include "framework.h"

BTNPause::BTNPause(float px, float py) : Button(px, py)
{}

BTNPause::~BTNPause()
{}

void BTNPause::start()
{
	setImage("Asset/UI/btnPause.bmp");
}

void BTNPause::onClick()
{
	cout << "===�Ͻ�����...��ư�� Ŭ����====" << endl;
}