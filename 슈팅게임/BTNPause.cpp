#include "framework.h"

BTNPause::BTNPause(float px, float py) : Button(px, py)
{
	
}

BTNPause::~BTNPause()
{}

void BTNPause::start()
{
	setImage("Asset/UI/btnPause.bmp");
}

void BTNPause::onClick()
{
	cout << "===일시중지...버튼이 클릭됨====" << endl;
	
	if (GameManager::getPause() == true)  //중지됨
	{
		Time::timeScale = 1.0f;
		GameManager::setPause(false);
	}
	else { //중지아님
		
		Time::timeScale = 0.0f;
		GameManager::setPause(true);
	}	
}