#pragma once

#include "GameObject.h"
#include "HPBar.h"
#include "PopupMenu.h"

class UIManager : public GameObject
{
private:

	//�˾��޴� ..������ ����//
	PopupMenu* menu;

	//�÷��̾� ü�¹�..������ ����//
	HPBar* hpBar;
public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
