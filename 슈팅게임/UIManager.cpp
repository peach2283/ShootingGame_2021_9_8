#include "framework.h"

UIManager::UIManager() : GameObject("","", true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::start()
{
	//현재 씬포인터 가져오기//
	string name = SceneManager::getActiveScene()->getName();

	if (name == "TitleScene")
	{
		///////////////*****타이틀씬 UI들*****////////////////////
		//타이틀 메뉴(버튼등)//
		instantiate(new Start(260, 400), UI_LAYER);
		instantiate(new Mode(260, 455), UI_LAYER);
		instantiate(new Option(260, 510), UI_LAYER);
		instantiate(new Exit(260, 565), UI_LAYER);
	}
	else if (name == "GameScene") {

		///////////////*****게임씬 UI들*****////////////////////
		//UI 객체...추가하기//
		instantiate(new BTNExit(420, 5), UI_LAYER);
		instantiate(new BTNPause(370, 5), UI_LAYER);

		//팝업메뉴 추가하기//
		instantiate(new PopupMenu(117.5, 305.5), UI_LAYER);

		//플레이어 체력바 추가하기//
		instantiate(new HPBar(100, 300), UI_LAYER);
	}
}

void UIManager::update()
{
	//현재 씬포인터 가져오기//
	string name = SceneManager::getActiveScene()->getName();

	if (name == "TitleScene")
	{
	
	}
	else if (name == "GameScene")
	{
		//팝업메뉴..보이기 숨기기//
		if (GameManager::getPause() == true)
		{
			//팝업메뉴 보이기
			GameObject* menu = ObjectManager::find("팝업메뉴");

			if (menu != nullptr)
			{
				menu->setActive(true);
			}
			else {
				cout << "----팝업메뉴 객체를...찾지못함 ----" << endl;
			}
		}
		else {
			//팝업메뉴 숨기기
			GameObject* menu = ObjectManager::find("팝업메뉴");

			if (menu != nullptr)
			{
				menu->setActive(false);
			}
			else {
				cout << "----팝업메뉴 객체를...찾지못함 ----" << endl;
			}
		}
	}
}