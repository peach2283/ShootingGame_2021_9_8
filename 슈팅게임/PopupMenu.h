#pragma once

#include "Sprite.h"
#include "Button.h"

/////////�ľ��޴�...Ŭ����///////
class PopupMenu : public Sprite
{
private:
public:
	PopupMenu(float px, float py);
	~PopupMenu();

	void start();
	void update();
};

/////�˾��޴�..��ư Ŭ������/////
///////�̾��ϱ� ��ư ///////////
class ItemResume : public Button
{
private:
public:
	ItemResume(float px, float py);
	~ItemResume();

	void start();
	void onClick();
};

///////�ٽ��ϱ� ��ư ///////////
class ItemRestart : public Button
{
private:
public:
	ItemRestart(float px, float py);
	~ItemRestart();

	void start();
	void onClick();
};

///////����(Ÿ��Ʋ)���� ��ư ///////////
class ItemMain : public Button
{
private:
public:
	ItemMain(float px, float py);
	~ItemMain();

	void start();
	void onClick();
};


///////������ ��ư ///////////
class ItemExit : public Button
{
private:
public:
	ItemExit(float px, float py);
	~ItemExit();

	void start();
	void onClick();
};
