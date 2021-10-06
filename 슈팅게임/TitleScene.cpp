#include "framework.h"

TitleScene::TitleScene() : Scene("TitleScene")
{}

TitleScene::~TitleScene()
{}

void TitleScene::load()
{
	//Ÿ��Ʋ ���//
	ObjectManager::instantiate(new TitleBG(), 0);

	//Ÿ��Ʋ �޴�(��ư��)//
	ObjectManager::instantiate(new Start (260, 400), UI_LAYER);
	ObjectManager::instantiate(new Mode  (260, 455), UI_LAYER);
	ObjectManager::instantiate(new Option(260, 510), UI_LAYER);
	ObjectManager::instantiate(new Exit  (260, 565), UI_LAYER);
}