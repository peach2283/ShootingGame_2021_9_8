#include "framework.h"

TitleScene::TitleScene() : Scene("TitleScene")
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//타이틀 배경//
	ObjectManager::instantiate(new TitleBG(), 0);

	//UIManager 추가하기//
	ObjectManager::instantiate(new UIManager(), 0);
}