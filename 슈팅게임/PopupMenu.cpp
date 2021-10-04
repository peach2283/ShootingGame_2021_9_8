#include "framework.h"

/////////****************파업메뉴...클래스**********************///////
PopupMenu::PopupMenu(float px, float py) : Sprite("","",true, px, py)
{}

PopupMenu::~PopupMenu()
{}

void PopupMenu::start()
{
	//메뉴 배경(박스)이미지 로드하기//
	setImage("Asset/UI/menu.bmp");

	//메뉴 버튼..자식객체 추가하기////
	addChildObject(new ItemResume (17, 19),  UI_LAYER);
	addChildObject(new ItemRestart(17, 57),  UI_LAYER);
	addChildObject(new ItemMain   (17, 95),  UI_LAYER);
	addChildObject(new ItemExit   (17, 133), UI_LAYER);
}


///////****************이어하기 버튼****************///////////
ItemResume::ItemResume(float px, float py) : Button(px, py)
{}

ItemResume::~ItemResume()
{}

void ItemResume::start()
{
	setImage("Asset/UI/itemResume.bmp");
}

void ItemResume::onClick()
{
	cout << "---이어하기 버튼 클릭됨----" << endl;
}

///////****************다시하기 버튼****************///////////
ItemRestart::ItemRestart(float px, float py) : Button(px, py)
{}

ItemRestart::~ItemRestart()
{}

void ItemRestart::start()
{
	setImage("Asset/UI/itemRestart.bmp");
}

void ItemRestart::onClick()
{
	cout << "---다시하기 버튼 클릭됨----" << endl;
}

///////****************메인으로 버튼****************///////////
ItemMain::ItemMain(float px, float py) : Button(px, py)
{}

ItemMain::~ItemMain()
{}

void ItemMain::start()
{
	setImage("Asset/UI/itemMain.bmp");
}

void ItemMain::onClick()
{
	cout << "---메인(타이틀)로 가기 버튼 클릭됨----" << endl;
}

///////****************끝내기 버튼****************///////////
ItemExit::ItemExit(float px, float py) : Button(px, py)
{}

ItemExit::~ItemExit()
{}

void ItemExit::start()
{
	setImage("Asset/UI/itemExit.bmp");
}

void ItemExit::onClick()
{
	//cout << "---끝내기 버튼 클릭됨----" << endl;
	Application::quit();
}