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
	cout << "===일시중지...버튼이 클릭됨====" << endl;
}