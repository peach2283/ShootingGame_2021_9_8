#include "framework.h"

EndingScene::EndingScene() : Scene("EndingScene")
{}

EndingScene::~EndingScene()
{}

void EndingScene::load()
{
	ObjectManager::instantiate(new UIManager(), 0);
	ObjectManager::instantiate(new EndingBG(80,180), 0);
}