#include "framework.h"

UIManager::UIManager() : GameObject("","", true, 0,0)
{}

UIManager::~UIManager()
{}

void UIManager::start()
{
	//UI ��ü...�߰��ϱ�//
	ObjectManager::instantiate(new BTNExit(420, 5), UI_LAYER);
	ObjectManager::instantiate(new BTNPause(370, 5), UI_LAYER);

	//�˾��޴� �߰��ϱ�//
	ObjectManager::instantiate(new PopupMenu(117.5, 305.5), UI_LAYER);
}

void UIManager::update()
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