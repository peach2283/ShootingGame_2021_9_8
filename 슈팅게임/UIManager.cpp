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
		hpBar = (HPBar*)instantiate(new HPBar(10, 20), UI_LAYER);

		//�÷��̾� ī��Ʈ..������..�߰��ϱ�//
		playerIcon[0] = (PlayerIcon * )  instantiate(new PlayerIcon(200, 5), UI_LAYER);
		playerIcon[1] = (PlayerIcon  *)  instantiate(new PlayerIcon(250, 5), UI_LAYER);
		playerIcon[2] = (PlayerIcon  *)  instantiate(new PlayerIcon(300, 5), UI_LAYER);

		//��ź ī��Ʈ...������ ... �߰��ϱ�
		bombIcon[0] = (BombIcon*)instantiate(new BombIcon(10 , 740), UI_LAYER);
		bombIcon[1] = (BombIcon*)instantiate(new BombIcon(35 , 740), UI_LAYER);
		bombIcon[2] = (BombIcon*)instantiate(new BombIcon(60 , 740), UI_LAYER);
		bombIcon[3] = (BombIcon*)instantiate(new BombIcon(85 , 740), UI_LAYER);
		bombIcon[4] = (BombIcon*)instantiate(new BombIcon(110, 740), UI_LAYER);

		//�ؽ�Ʈ.UI �׽�Ʈ�ϱ�
		instantiate(new Text(100, 100), UI_LAYER);
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
		hpBar->setFillAmount(hp / 100.0f);

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
	}
}