#include "framework.h"

UIManager::UIManager() : GameObject("","", true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::start()
{
	//UI °´Ã¼...Ãß°¡ÇÏ±â//
	ObjectManager::instantiate(new BTNExit(420, 5), UI_LAYER);
	ObjectManager::instantiate(new BTNPause(370, 5), UI_LAYER);

	//ÆË¾÷¸Þ´º Ãß°¡ÇÏ±â//
	ObjectManager::instantiate(new PopupMenu(117.5, 305.5), UI_LAYER);
}

void UIManager::update()
{
	//ÆË¾÷¸Þ´º..º¸ÀÌ±â ¼û±â±â//
	if (GameManager::getPause() == true)
	{
		//ÆË¾÷¸Þ´º º¸ÀÌ±â
		GameObject* menu = ObjectManager::find("ÆË¾÷¸Þ´º");

		if (menu != nullptr)
		{
			menu->setActive(true);
		}
		else {
			cout << "----ÆË¾÷¸Þ´º °´Ã¼¸¦...Ã£Áö¸øÇÔ ----" << endl;
		}
	}
	else {
		//ÆË¾÷¸Þ´º ¼û±â±â
		GameObject* menu = ObjectManager::find("ÆË¾÷¸Þ´º");

		if (menu != nullptr)
		{
			menu->setActive(false);
		}
		else {
			cout << "----ÆË¾÷¸Þ´º °´Ã¼¸¦...Ã£Áö¸øÇÔ ----" << endl;
		}
	}
}