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
		hpBar = (HPBar*)instantiate(new HPBar(36, 20), UI_LAYER);

		//플레이어 카운트..아이콘..추가하기//
		playerIcon[0] = (PlayerIcon * )  instantiate(new PlayerIcon(222, 5), UI_LAYER);
		playerIcon[1] = (PlayerIcon  *)  instantiate(new PlayerIcon(272, 5), UI_LAYER);
		playerIcon[2] = (PlayerIcon  *)  instantiate(new PlayerIcon(322, 5), UI_LAYER);

		//폭탄 카운트...아이콘 ... 추가하기
		bombIcon[0] = (BombIcon*)instantiate(new BombIcon(10 , 740), UI_LAYER);
		bombIcon[1] = (BombIcon*)instantiate(new BombIcon(35 , 740), UI_LAYER);
		bombIcon[2] = (BombIcon*)instantiate(new BombIcon(60 , 740), UI_LAYER);
		bombIcon[3] = (BombIcon*)instantiate(new BombIcon(85 , 740), UI_LAYER);
		bombIcon[4] = (BombIcon*)instantiate(new BombIcon(110, 740), UI_LAYER);

		//텍스트 UI 추가하기//
		Text * text=(Text*)instantiate(new Text(5, 36), UI_LAYER);  //체력 텍스트

		text->setText(L"HP");
		text->setColor(255, 255, 255);
		text->setSize(16);
		text->setFontFamily("Asset/font/Medium.ttf");

		text = (Text*)instantiate(new Text(5, 68), UI_LAYER);  //점수 텍스트

		text->setText(L"SCORE");
		text->setColor(255, 255, 255);
		text->setSize(16);
		text->setFontFamily("Asset/font/Medium.ttf");

		text = (Text*)instantiate(new Text(250, 780), UI_LAYER);  //버전 텍스트

		//버전 정보 문자열 만들기//
		WCHAR buffer[100];
		wsprintf(buffer, L"WinAPI Shooting (Ver %d.%d)", VER_MAJOR, VER_MINOR);

		text->setText(buffer);
		text->setColor(0, 0, 0);
		text->setSize(16);
		text->setFontFamily("Asset/font/Medium.ttf");

		//점수 텍스트 UI 만들기
		scoreText = (Text*)instantiate(new Text(78, 70), UI_LAYER);  //점수 출력 텍스트

		scoreText->setText(L"0");
		scoreText->setColor(0, 0, 0);
		scoreText->setSize(18);
		scoreText->setFontFamily("Asset/font/Bold.ttf");

	}
	else if (name == "EndingScene")
	{		
		//텍스트 UI 추가하기//
		Text* text = (Text*)instantiate(new Text(84, 60), UI_LAYER);  //체력 텍스트

		text->setText(L"MISSION");
		text->setColor(255, 255, 255);
		text->setSize(64);
		text->setFontFamily("Asset/font/Medium.ttf");

		text = (Text*)instantiate(new Text(84, 120), UI_LAYER);  //체력 텍스트

		text->setText(L"COMPLETE");
		text->setColor(255, 0, 0);
		text->setSize(48);
		text->setFontFamily("Asset/font/Medium.ttf");

		//종료 버튼 추가하기(Tile 버튼 재사용)
		instantiate(new Exit(150, 700), UI_LAYER);
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
		WCHAR buffer[10];

		hp = (hp < 0) ? 0 : hp;

		wsprintf(buffer, L"%d", (int)hp);

		hpBar->setFillAmount(hp / 100.0f);
		hpBar->setText(wstring(buffer));

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

		//게임 점수 화면 출력하기//
		int score = GameManager::getScore();
		
		wsprintf(buffer, L"%d", score);
		scoreText->setText(wstring(buffer));
	}
}