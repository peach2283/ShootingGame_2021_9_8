#include "framework.h"

Boss::Boss(float px, float py) :Sprite("보스", "", true, px, py)
{
	this->childCount = 0;
}

Boss::~Boss()
{}

void Boss::start()
{
	//폭발되지 안은 보스
	setImage("Asset/보스.bmp", 0, 0, 493, 206);

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
	addChildObject(new Wing(364, 426, 32, 16,	  350, 90), 0);  //오른쪽 세번째
	addChildObject(new Wing(399, 426, 32, 16,     405, 84), 0);  //오른쪽 네번째

	addChildObject(new Wing(404, 406, 28, 15,	  206, 98), 0);  //왼쪽  첫번째
	addChildObject(new Wing(369, 406, 32, 16,	  158, 94), 0);  //왼쪽  두번째
	addChildObject(new Wing(334, 406, 32, 16,	  110, 90), 0);  //왼쪽  세번째
	addChildObject(new Wing(299, 406, 32, 16,	   62, 85), 0);  //왼쪽  네번째

	//날개위 건 자식객체
	addChildObject(new Gun(94,  71), 0);
	addChildObject(new Gun(142, 71), 0);
	addChildObject(new Gun(190, 71), 0);

	addChildObject(new Gun(238, 63), 0);

	addChildObject(new Gun(286, 71), 0);
	addChildObject(new Gun(334, 71), 0);
	addChildObject(new Gun(382, 71), 0);

	//날개아래 대포 자식객체
	addChildObject(new Cannon(265 + 5, 97 + 10), 0);
	addChildObject(new Cannon(206 - 5, 97 + 10), 0);

	//레이더 자식객체
	addChildObject(new Radar(241, 105), 0);
	addChildObject(new Radar(241, 117), 0);
}

void Boss::onChildDestroyed()
{
	childCount++;

	cout << "소멸된 자식객체 갯수 " << childCount <<  endl;

	if (childCount == 1)
	{
		float px = getPx();
		float py = getPy();

		//보스 폭발 시키기
		instantiate(new BossExp(px + 165, py -30), 1);

		instantiate(new BossExp(px + 25,  py), 1);
		instantiate(new BossExp(px + 305, py), 1);

		instantiate(new BossExp(px + 165, py+70), 1);

		//보스 제거하기
		destroy(this); 

		//폭발된 보스 객체(DeadBoss) 생성하기//		
		instantiate(new DeadBoss(px+47, py+20), 0);
	}
}