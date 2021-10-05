#include "framework.h"

/////////****************�ľ��޴�...Ŭ����**********************///////
PopupMenu::PopupMenu(float px, float py) : Sprite("","�˾��޴�",false, px, py)
{}

PopupMenu::~PopupMenu()
{}

void PopupMenu::start()
{
	//�޴� ���(�ڽ�)�̹��� �ε��ϱ�//
	setImage("Asset/UI/menu.bmp");

	//�޴� ��ư..�ڽİ�ü �߰��ϱ�////
	addChildObject(new ItemResume (17, 19),  UI_LAYER);
	addChildObject(new ItemRestart(17, 57),  UI_LAYER);
	addChildObject(new ItemMain   (17, 95),  UI_LAYER);
	addChildObject(new ItemExit   (17, 133), UI_LAYER);
}

void PopupMenu::update()
{
	if (GameManager::getPause() == true)
	{
		setActive(true); //�޴� ���̱�
	}
	else {
		setActive(false); //�޴� �����
	}
}

///////****************�̾��ϱ� ��ư****************///////////
ItemResume::ItemResume(float px, float py) : Button(px, py, false)
{}

ItemResume::~ItemResume()
{}

void ItemResume::start()
{
	setImage("Asset/UI/itemResume.bmp");
}

void ItemResume::onClick()
{
	cout << "---�̾��ϱ� ��ư Ŭ����----" << endl;

	GameManager::setPause(false);  //�Ͻ�����...����
	Time::timeScale = 1;           //Ÿ�ӽ����� ����
}

///////****************�ٽ��ϱ� ��ư****************///////////
ItemRestart::ItemRestart(float px, float py) : Button(px, py, false)
{}

ItemRestart::~ItemRestart()
{}

void ItemRestart::start()
{
	setImage("Asset/UI/itemRestart.bmp");
}

void ItemRestart::onClick()
{
	cout << "---�ٽ��ϱ� ��ư Ŭ����----" << endl;
}

///////****************�������� ��ư****************///////////
ItemMain::ItemMain(float px, float py) : Button(px, py, false)
{}

ItemMain::~ItemMain()
{}

void ItemMain::start()
{
	setImage("Asset/UI/itemMain.bmp");
}

void ItemMain::onClick()
{
	cout << "---����(Ÿ��Ʋ)�� ���� ��ư Ŭ����----" << endl;
}

///////****************������ ��ư****************///////////
ItemExit::ItemExit(float px, float py) : Button(px, py, false)
{}

ItemExit::~ItemExit()
{}

void ItemExit::start()
{
	setImage("Asset/UI/itemExit.bmp");
}

void ItemExit::onClick()
{
	//cout << "---������ ��ư Ŭ����----" << endl;
	Application::quit();
}