#pragma once

#include "Sprite.h"
#include "Button.h"

/////////파업메뉴...클래스///////
class PopupMenu : public Sprite
{
private:
public:
	PopupMenu(float px, float py);
	~PopupMenu();

	void start();
	void update();
};

/////팝업메뉴..버튼 클래스들/////
///////이어하기 버튼 ///////////
class ItemResume : public Button
{
private:
public:
	ItemResume(float px, float py);
	~ItemResume();

	void start();
	void onClick();
};

///////다시하기 버튼 ///////////
class ItemRestart : public Button
{
private:
public:
	ItemRestart(float px, float py);
	~ItemRestart();

	void start();
	void onClick();
};

///////메인(타이틀)으로 버튼 ///////////
class ItemMain : public Button
{
private:
public:
	ItemMain(float px, float py);
	~ItemMain();

	void start();
	void onClick();
};


///////끝내기 버튼 ///////////
class ItemExit : public Button
{
private:
public:
	ItemExit(float px, float py);
	~ItemExit();

	void start();
	void onClick();
};
