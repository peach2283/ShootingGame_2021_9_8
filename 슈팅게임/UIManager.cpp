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
		instantiate(new PlayerIcon(200, 5), UI_LAYER);
		instantiate(new PlayerIcon(250, 5), UI_LAYER);
		instantiate(new PlayerIcon(300, 5), UI_LAYER);
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
	}
}