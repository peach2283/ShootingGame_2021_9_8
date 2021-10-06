#pragma once

#include "Button.h"

/////// ���� ��ư ////////
class Start : public Button
{
private:
public:
	Start(float px, float py);
	~Start();

	void start();
	void onClick();
};

////// ��� ��ư/////////
class Mode : public Button
{
private:
public: 
	Mode(float px, float py);
	~Mode();

	void start();
	void onClick();
};

////// �ɼ� ��ư //////
class Option : public Button
{
private:
public:
	Option(float px, float py);
	~Option();

	void start();
	void onClick();
};

////// ������ ��ư //////
class Exit : public Button
{
private:
public:
	Exit(float px, float py);
	~Exit();

	void start();
	void onClick();
};
