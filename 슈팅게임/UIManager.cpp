#include "framework.h"

UIManager::UIManager() : GameObject("","", true, 0,0)
{}

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
		instantiate(new PopupMenu(117.5, 305.5), UI_LAYER);

		//�÷��̾� ü�¹� �߰��ϱ�//
		instantiate(new HPBar(100, 300), UI_LAYER);
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
			//�˾��޴� ���̱�
			GameObject* menu = ObjectManager::find("�˾��޴�");

			if (menu != nullptr)
			{
				menu->setActive(true);
			}
			else {
				cout << "----�˾��޴� ��ü��...ã������ ----" << endl;
			}
		}
		else {
			//�˾��޴� �����
			GameObject* menu = ObjectManager::find("�˾��޴�");

			if (menu != nullptr)
			{
				menu->setActive(false);
			}
			else {
				cout << "----�˾��޴� ��ü��...ã������ ----" << endl;
			}
		}
	}
}