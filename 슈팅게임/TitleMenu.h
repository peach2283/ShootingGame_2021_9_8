#pragma once

#include "Button.h"

/////// 시작 버튼 ////////
class Start : public Button
{
private:
public:
	Start(float px, float py);
	~Start();

	void start();
	void onClick();
};

////// 모드 버튼/////////
class Mode : public Button
{
private:
public: 
	Mode(float px, float py);
	~Mode();

	void start();
	void onClick();
};

////// 옵션 버튼 //////
class Option : public Button
{
private:
public:
	Option(float px, float py);
	~Option();

	void start();
	void onClick();
};

////// 끝내기 버튼 //////
class Exit : public Button
{
private:
public:
	Exit(float px, float py);
	~Exit();

	void start();
	void onClick();
};
