#include "framework.h"

TitleScene::TitleScene() : Scene()
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//Ÿ��Ʋ ���//
	ObjectManager::instantiate(new TitleBG(), 0);

	//Ÿ��Ʋ �޴�(��ư��)//
}