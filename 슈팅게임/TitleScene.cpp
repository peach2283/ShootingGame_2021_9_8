#include "framework.h"

TitleScene::TitleScene() : Scene("TitleScene")
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//Ÿ��Ʋ ���//
	ObjectManager::instantiate(new TitleBG(), 0);

	//UIManager �߰��ϱ�//
	ObjectManager::instantiate(new UIManager(), 0);
}