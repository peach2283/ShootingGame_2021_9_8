#include "framework.h"

GameBG::GameBG():Sprite("���ӹ��", "", true, 0, 0)
{}

GameBG::~GameBG()
{}

void GameBG::start()
{
	//��������Ʈ �̹��� �ε�//
	setImage("Asset/���ӹ��.bmp");
}

void GameBG::update()
{}