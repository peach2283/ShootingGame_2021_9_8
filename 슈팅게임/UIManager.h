#pragma once

#include "GameObject.h"
#include "HPBar.h"
#include "PopupMenu.h"

class UIManager : public GameObject
{
private:

	//팝업메뉴 ..포인터 변수//
	PopupMenu* menu;

	//플레이어 체력바..포인터 변수//
	HPBar* hpBar;
public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
