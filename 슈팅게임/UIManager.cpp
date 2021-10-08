#include "framework.h"

UIManager::UIManager() : GameObject("","", true, 0,0)
{
	this->hpBar = nullptr;
	this->menu  = nullptr;
}

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
		menu = (PopupMenu*)instantiate(new PopupMenu(117.5, 305.5), UI_LAYER);

		//플레이어 체력바 추가하기//
		hpBar = (HPBar*)instantiate(new HPBar(10, 20), UI_LAYER);

		//플레이어 카운트..아이콘..추가하기//
		instantiate(new PlayerIcon(200, 5), UI_LAYER);
		instantiate(new PlayerIcon(250, 5), UI_LAYER);
		instantiate(new PlayerIcon(300, 5), UI_LAYER);
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
			menu->setActive(true);
		}
		else {
			
			menu->setActive(false);
		}

		//플레이어 체력바..변경하기//
		float hp = GameManager::getPlayerHp();
		hpBar->setFillAmount(hp / 100.0f);
	}
}