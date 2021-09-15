#include "framework.h"

Boss::Boss(float px, float py) :Sprite("", "", true, px, py)
{}

Boss::~Boss()
{}

void Boss::start()
{
	//폭발되지 안은 보스
	setImage("Asset/보스.bmp", 0, 0, 493, 206);

	//폭발된 보스
	//setImage("Asset/보스.bmp", 0, 613, 385, 182);

	//**************보스 자식객체 추가하기***************//

	//프로펠러 자식객체
	addChildObject(new Propeller(63,  41), 0);
	addChildObject(new Propeller(111, 41), 0);
	addChildObject(new Propeller(159, 41), 0);

	addChildObject(new Propeller(302, 41), 0);
	addChildObject(new Propeller(350, 41), 0);
	addChildObject(new Propeller(398, 41), 0);

	//날개 자식객체
	addChildObject(new Wing(298, 425, 30, 18,     256, 97), 0);  //오른쪽 첫번째
	addChildObject(new Wing(329, 426, 32, 16,     302, 94), 0);  //오른쪽 두번째
}