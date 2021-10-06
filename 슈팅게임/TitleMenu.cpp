#include "framework.h"

/////// ���� ��ư ////////
Start::Start(float px, float py) : Button(px, py)
{}
Start::~Start()
{}

void Start::start()
{
	setImage("Asset/UI/����.bmp");
}

void Start::onClick()
{
	cout << "==���� ��ư==" << endl;
	SceneManager::loadScene("GameScene");
}

////// ��� ��ư/////////
Mode::Mode(float px, float py) : Button(px, py)
{}

Mode::~Mode()
{}

void Mode::start()
{
	setImage("Asset/UI/���.bmp");
}

void Mode::onClick()
{
	cout << "==��� ��ư==" << endl;
}

////// �ɼ� ��ư //////
Option::Option(float px, float py) : Button(px, py)
{}

Option::~Option()
{}

void Option::start()
{
	setImage("Asset/UI/�ɼ�.bmp");
}

void Option::onClick()
{
	cout << "==�ɼ� ��ư==" << endl;
}


////// ������ ��ư //////
Exit::Exit(float px, float py) : Button(px, py)
{}

Exit::~Exit()
{}

void Exit::start()
{
	setImage("Asset/UI/������.bmp");
}

void Exit::onClick()
{	
	Application::quit();
}