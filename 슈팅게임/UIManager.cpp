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
		playerIcon[0] = (PlayerIcon * )  instantiate(new PlayerIcon(200, 5), UI_LAYER);
		playerIcon[1] = (PlayerIcon  *)  instantiate(new PlayerIcon(250, 5), UI_LAYER);
		playerIcon[2] = (PlayerIcon  *)  instantiate(new PlayerIcon(300, 5), UI_LAYER);

		//폭탄 카운트...아이콘 ... 추가하기
		bombIcon[0] = (BombIcon*)instantiate(new BombIcon(10 , 740), UI_LAYER);
		bombIcon[1] = (BombIcon*)instantiate(new BombIcon(35 , 740), UI_LAYER);
		bombIcon[2] = (BombIcon*)instantiate(new BombIcon(60 , 740), UI_LAYER);
		bombIcon[3] = (BombIcon*)instantiate(new BombIcon(85 , 740), UI_LAYER);
		bombIcon[4] = (BombIcon*)instantiate(new BombIcon(110, 740), UI_LAYER);

		//텍스트.UI 테스트하기
		instantiate(new Text(100, 100), UI_LAYER);
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

		//남은 플레이어 갯수 아이콘..보여주기//
		int  count = GameManager::getPlayerCount();

		for (int i = 0; i < 3; i++)
		{
			if (i < count)
			{
			    //보이기
				playerIcon[i]->setActive(true);
			}
			else {
				//숨기기
				playerIcon[i]->setActive(false);
			}
		}


		//남은 폭탄갯수 아이콘..보여주기//
		count = GameManager::getBombCount();

		for (int i = 0; i < 5; i++)
		{
			if (i < count)
			{
				bombIcon[i]->setActive(true);
			}
			else {

				bombIcon[i]->setActive(false);
			}
		}
	}
}