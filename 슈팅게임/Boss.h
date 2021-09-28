#pragma once

#include "Sprite.h"

#define MAX_GUN_FIRE    20
#define MAX_CANNON_FIRE 10

class Boss : public Sprite
{
	//보스 상태//
	enum class State {moveDown=0, attack=1};
private:

	int childCount;

	float gunFireTimer; 
	float gunFireDelay;

	float cannonFireTimer;
	float cannonFireDelay;

	//보스건 자식객체의...발사 여부 배열
	bool gunFire[7][MAX_GUN_FIRE] = {   { true, true,  false, false, false,    false, true, true, false,    false, false, false, true, true,     false, false, false, false  },  //건1
										{ true, true,  false, false, false,    false, true, true, false,    false, false, false, true, true,     false, false, false, false  },  //건2
										{ true, true,  false, false, false,    false, true, true, false,    false, false, false, true, true,     false, false, false, false  },  //건3

										{ true, true,  false, true, true,      false, true, true, false,     true, true, false, true, true,      false, true, true, false  },  //건4

										{ false, false, false, true, true,     false, false, false, false,   true, true, false, false, false,     false, true, true, false  },  //건5
										{ false, false, false, true, true,     false, false, false, false,   true, true, false, false, false,     false, true, true, false  },  //건6
										{ false, false, false, true, true,     false, false, false, false,   true, true, false, false, false,     false, true, true, false  },  //건7
									 };
	int gunFireIndex;

	//보스 캐논 자식객체의..발사 여부 배열
	bool cannonFire[2][MAX_CANNON_FIRE] = { {true,  true,  false, false, false, false, false, false, true, true },
											{false, false, false, false, true,   true, false, false, true, true } };

	int cannonFireIndex;

	//보스 이동 속도
	float speed;

	//보스 상태 변수
	State state;

public:
	Boss(float px, float py);
	~Boss();

	void start();
	void update();

	//자식객체가..제거되었음을 알려주는 이벤트 함수//
	void onChildDestroyed();
};
