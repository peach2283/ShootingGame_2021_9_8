#include "framework.h"

/////// 시작 버튼 ////////
Start::Start(float px, float py) : Button(px, py)
{}
Start::~Start()
{}

void Start::start()
{
	setImage("Asset/UI/시작.bmp");
}

void Start::onClick()
{
	cout << "==시작 버튼==" << endl;
	SceneManager::loadScene("GameScene");
}

////// 모드 버튼/////////
Mode::Mode(float px, float py) : Button(px, py)
{}

Mode::~Mode()
{}

void Mode::start()
{
	setImage("Asset/UI/모드.bmp");
}

void Mode::onClick()
{
	cout << "==모드 버튼==" << endl;
}

////// 옵션 버튼 //////
Option::Option(float px, float py) : Button(px, py)
{}

Option::~Option()
{}

void Option::start()
{
	setImage("Asset/UI/옵션.bmp");
}

void Option::onClick()
{
	cout << "==옵션 버튼==" << endl;
}


////// 끝내기 버튼 //////
Exit::Exit(float px, float py) : Button(px, py)
{}

Exit::~Exit()
{}

void Exit::start()
{
	setImage("Asset/UI/끝내기.bmp");
}

void Exit::onClick()
{	
	Application::quit();
}