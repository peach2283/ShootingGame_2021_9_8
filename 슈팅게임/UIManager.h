#pragma once

#include "GameObject.h"
#include "HPBar.h"
#include "PopupMenu.h"
#include "PlayerIcon.h"
#include "BombIcon.h"
#include "Text.h"

class UIManager : public GameObject
{
private:

	//�˾��޴� ..������ ����//
	PopupMenu* menu;

	//�÷��̾� ü�¹�..������ ����//
	HPBar* hpBar;

	//�÷��̾� ���� ������..������ �迭//
	PlayerIcon* playerIcon[3];

	//��ź ���� ������...������ �迭//
	BombIcon* bombIcon[5];

	//���� ��� �ؽ�Ʈ UI//
	Text* scoreText;

public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
