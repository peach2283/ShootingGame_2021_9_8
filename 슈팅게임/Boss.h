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

	//�ڽİ�ü��..���ŵǾ����� �˷��ִ� �̺�Ʈ �Լ�//
	void onChildDestroyed();
};
