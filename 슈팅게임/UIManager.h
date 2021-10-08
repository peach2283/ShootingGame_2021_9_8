#pragma once

#include "GameObject.h"
#include "HPBar.h"
#include "PopupMenu.h"
#include "PlayerIcon.h"
#include "BombIcon.h"

class UIManager : public GameObject
{
private:

	//팝업메뉴 ..포인터 변수//
	PopupMenu* menu;

	//플레이어 체력바..포인터 변수//
	HPBar* hpBar;

	//플레이어 갯수 아이콘..포인터 배열//
	PlayerIcon* playerIcon[3];

	//폭탄 갯수 아이콘...포인터 배열//
	BombIcon* bombIcon[5];

public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
