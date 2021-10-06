#include "framework.h"

TitleScene::TitleScene() : Scene("TitleScene")
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//타이틀 배경//
	ObjectManager::instantiate(new TitleBG(), 0);

	//타이틀 메뉴(버튼등)//
	ObjectManager::instantiate(new Start (260, 400), UI_LAYER);
	ObjectManager::instantiate(new Mode  (260, 455), UI_LAYER);
	ObjectManager::instantiate(new Option(260, 510), UI_LAYER);
	ObjectManager::instantiate(new Exit  (260, 565), UI_LAYER);
}