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
	//���� �������� ��������//
	string name = SceneManager::getActiveScene()->getName();

	if (name == "TitleScene")
	{
		///////////////*****Ÿ��Ʋ�� UI��*****////////////////////
		//Ÿ��Ʋ �޴�(��ư��)//
		instantiate(new Start(260, 400), UI_LAYER);
		instantiate(new Mode(260, 455), UI_LAYER);
		instantiate(new Option(260, 510), UI_LAYER);
		instantiate(new Exit(260, 565), UI_LAYER);
	}
	else if (name == "GameScene") {

		///////////////*****���Ӿ� UI��*****////////////////////
		//UI ��ü...�߰��ϱ�//
		instantiate(new BTNExit(420, 5), UI_LAYER);
		instantiate(new BTNPause(370, 5), UI_LAYER);

		//�˾��޴� �߰��ϱ�//
		menu = (PopupMenu*)instantiate(new PopupMenu(117.5, 305.5), UI_LAYER);

		//�÷��̾� ü�¹� �߰��ϱ�//
		hpBar = (HPBar*)instantiate(new HPBar(36, 20), UI_LAYER);

		//�÷��̾� ī��Ʈ..������..�߰��ϱ�//
		playerIcon[0] = (PlayerIcon * )  instantiate(new PlayerIcon(222, 5), UI_LAYER);
		playerIcon[1] = (PlayerIcon  *)  instantiate(new PlayerIcon(272, 5), UI_LAYER);
		playerIcon[2] = (PlayerIcon  *)  instantiate(new PlayerIcon(322, 5), UI_LAYER);

		//��ź ī��Ʈ...������ ... �߰��ϱ�
		bombIcon[0] = (BombIcon*)instantiate(new BombIcon(10 , 740), UI_LAYER);
		bombIcon[1] = (BombIcon*)instantiate(new BombIcon(35 , 740), UI_LAYER);
		bombIcon[2] = (BombIcon*)instantiate(new BombIcon(60 , 740), UI_LAYER);
		bombIcon[3] = (BombIcon*)instantiate(new BombIcon(85 , 740), UI_LAYER);
		bombIcon[4] = (BombIcon*)instantiate(new BombIcon(110, 740), UI_LAYER);

		//�ؽ�Ʈ UI �߰��ϱ�//
		Text * text=(Text*)instantiate(new Text(5, 36), UI_LAYER);  //ü�� �ؽ�Ʈ

		text->setText(L"HP");
		text->setColor(255, 255, 255);
		text->setSize(16);
		text->setFontFamily("Asset/font/Medium.ttf");

		text = (Text*)instantiate(new Text(5, 68), UI_LAYER);  //���� �ؽ�Ʈ

		text->setText(L"SCORE");
		text->setColor(255, 255, 255);
		text->setSize(16);
		text->setFontFamily("Asset/font/Medium.ttf");

		text = (Text*)instantiate(new Text(250, 780), UI_LAYER);  //���� �ؽ�Ʈ

		//���� ���� ���ڿ� �����//
		WCHAR buffer[100];
		wsprintf(buffer, L"WinAPI Shooting (Ver %d.%d)", VER_MAJOR, VER_MINOR);

		text->setText(buffer);
		text->setColor(0, 0, 0);
		text->setSize(16);
		text->setFontFamily("Asset/font/Medium.ttf");

		//���� �ؽ�Ʈ UI �����
		scoreText = (Text*)instantiate(new Text(78, 70), UI_LAYER);  //���� ��� �ؽ�Ʈ

		scoreText->setText(L"0");
		scoreText->setColor(0, 0, 0);
		scoreText->setSize(18);
		scoreText->setFontFamily("Asset/font/Bold.ttf");

	}
	else if (name == "EndingScene")
	{		
		//�ؽ�Ʈ UI �߰��ϱ�//
		Text* text = (Text*)instantiate(new Text(84, 60), UI_LAYER);  //ü�� �ؽ�Ʈ

		text->setText(L"MISSION");
		text->setColor(255, 255, 255);
		text->setSize(64);
		text->setFontFamily("Asset/font/Medium.ttf");

		text = (Text*)instantiate(new Text(84, 120), UI_LAYER);  //ü�� �ؽ�Ʈ

		text->setText(L"COMPLETE");
		text->setColor(255, 0, 0);
		text->setSize(48);
		text->setFontFamily("Asset/font/Medium.ttf");

		//���� ��ư �߰��ϱ�(Tile ��ư ����)
		instantiate(new Exit(150, 700), UI_LAYER);
	}
}

void UIManager::update()
{
	//���� �������� ��������//
	string name = SceneManager::getActiveScene()->getName();

	if (name == "TitleScene")
	{
	
	}
	else if (name == "GameScene")
	{
		//�˾��޴�..���̱� �����//
		if (GameManager::getPause() == true)
		{			
			menu->setActive(true);
		}
		else {
			
			menu->setActive(false);
		}

		//�÷��̾� ü�¹�..�����ϱ�//
		float hp = GameManager::getPlayerHp();
		WCHAR buffer[10];

		hp = (hp < 0) ? 0 : hp;

		wsprintf(buffer, L"%d", (int)hp);

		hpBar->setFillAmount(hp / 100.0f);
		hpBar->setText(wstring(buffer));

		//���� �÷��̾� ���� ������..�����ֱ�//
		int  count = GameManager::getPlayerCount();

		for (int i = 0; i < 3; i++)
		{
			if (i < count)
			{
			    //���̱�
				playerIcon[i]->setActive(true);
			}
			else {
				//�����
				playerIcon[i]->setActive(false);
			}
		}


		//���� ��ź���� ������..�����ֱ�//
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

		//���� ���� ȭ�� ����ϱ�//
		int score = GameManager::getScore();
		
		wsprintf(buffer, L"%d", score);
		scoreText->setText(wstring(buffer));
	}
}