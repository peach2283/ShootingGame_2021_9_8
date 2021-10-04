#pragma once

#include "Sprite.h"

class Button : public Sprite
{
	enum class State{normal=0, pressed=1};

private:
	State state;
	
public:
	Button(float px, float py);
	Button(float px, float py, bool active);
	~Button();

	void start();
	void update();

	bool isMouseInImageRect();

	//Ŭ�� �̺�Ʈ �����Լ�//
	virtual void onClick();
};
