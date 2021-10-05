#include "framework.h"

TitleScene::TitleScene() : Scene()
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//타이틀 배경//
	ObjectManager::instantiate(new TitleBG(), 0);

	//타이틀 메뉴(버튼등)//
}