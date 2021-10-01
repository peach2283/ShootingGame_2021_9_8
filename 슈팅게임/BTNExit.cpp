#include "framework.h"

BTNExit::BTNExit(float px, float py) : Button(px, py)
{}

BTNExit::~BTNExit()
{}

void BTNExit::start()
{
	setImage("Asset/UI/btnExit.bmp");
}

void BTNExit::onClick()
{
	cout << "=====끝내기 버튼이 클릭됨====" << endl;
	Application::quit();
}