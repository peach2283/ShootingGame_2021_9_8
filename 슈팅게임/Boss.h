#pragma once

#include "Sprite.h"

#define MAX_GUN_FIRE 20

class Boss : public Sprite
{
private:

	int childCount;

	float fireTimer;
	float fireDelay;

	//������ �ڽİ�ü��...�߻� ���� �迭
	bool gunFire[7][MAX_GUN_FIRE] = {   { true, true,  false, false, false,    false, true, true, false,    false, false, false, true, true,     false, false, false, false  },  //��1
										{ true, true,  false, false, false,    false, true, true, false,    false, false, false, true, true,     false, false, false, false  },  //��2
										{ true, true,  false, false, false,    false, true, true, false,    false, false, false, true, true,     false, false, false, false  },  //��3

										{ true, true,  false, true, true,      false, true, true, false,     true, true, false, true, true,      false, true, true, false  },  //��4

										{ false, false, false, true, true,     false, false, false, false,   true, true, false, false, false,     false, true, true, false  },  //��5
										{ false, false, false, true, true,     false, false, false, false,   true, true, false, false, false,     false, true, true, false  },  //��6
										{ false, false, false, true, true,     false, false, false, false,   true, true, false, false, false,     false, true, true, false  },  //��7
									 };
	int gunFireIndex;

public:
	Boss(float px, float py);
	~Boss();

	void start();
	void update();

	//�ڽİ�ü��..���ŵǾ����� �˷��ִ� �̺�Ʈ �Լ�//
	void onChildDestroyed();
};
