#pragma once

#include "Sprite.h"

class Boss : public Sprite
{
private:

	int childCount;
public:
	Boss(float px, float py);
	~Boss();

	void start();

	//자식객체가..제거되었음을 알려주는 이벤트 함수//
	void onChildDestroyed();
};
