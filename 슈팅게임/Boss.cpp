#include "framework.h"

Boss::Boss(float px, float py) :Sprite("보스", "", true, px, py)
{
	this->childCount = 0;

	this->gunFireTimer	= 0;
	this->gunFireDelay	= 0.2;
	this->gunFireIndex	= 0;

	this->cannonFireTimer = 0;
	this->cannonFireDelay = 0.5;
	this->cannonFireIndex = 0;

	this->speed = 50;
	this->state = State::moveDown;

	this->attackPos = 60;
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
	addChildObject(new Gun("건1", 94,  71), 0); //건1
	addChildObject(new Gun("건2", 142, 71), 0); //건2
	addChildObject(new Gun("건3", 190, 71), 0); //건3

	addChildObject(new Gun("건4", 238, 63), 0); //건4

	addChildObject(new Gun("건5", 286, 71), 0); //건5
	addChildObject(new Gun("건6", 334, 71), 0); //건6
	addChildObject(new Gun("건7", 382, 71), 0); //건7

	//날개아래 대포 자식객체
	addChildObject(new Cannon("대포1", 265 + 5, 97 + 10), 0); //대포1
	addChildObject(new Cannon("대포2", 206 - 5, 97 + 10), 0); //대포2

	//레이더 자식객체
	addChildObject(new Radar(241, 105), 0);
	addChildObject(new Radar(241, 117), 0);

	//보스 전체...충돌체//
	addBoxCollider2D(230,  10, 33,  160);
	addBoxCollider2D(10,   60, 473, 40);
	addBoxCollider2D(190, 170, 113, 30);
}

void Boss::update()
{
	switch (state)
	{	
		case State::moveDown :
		{
			//이동하기
			move();

			//건발사하기
			bulletFire();

			//중지하고 공격상태 전이 조건검사
			int py = getPy();

			if (py >= attackPos)
			{
				state = State::attack;
			}
		}
		break;

		case State::attack :
		{
			//공격하기
			bulletFire();
			shellFire();
		}
		break;
	}
}

void Boss::move()
{
	//이동하기
	float dist = speed * Time::deltaTime;
	translate(0, dist);
}

void Boss::bulletFire()
{
	//건발사하기
	gunFireTimer = gunFireTimer + Time::deltaTime;

	if (gunFireTimer >= gunFireDelay)
	{
		//자식건 찾기
		string name[7] = { "건1", "건2", "건3", "건4", "건5", "건6", "건7" };

		for (int i = 0; i < 7; i++)
		{
			if (gunFire[i][gunFireIndex] == true)  //건배열에서..발사로..지정(true)되어 있으면..
			{
				Gun* gun = (Gun*)find(name[i]);

				if (gun != nullptr)
				{
					gun->onFire();
				}
			}
		}

		gunFireTimer = 0;
		gunFireIndex++;  //건배열의..발사인덱스 증가

		if (gunFireIndex >= MAX_GUN_FIRE)
		{
			gunFireIndex = 0;  //건배열의..처음부터 다시 발사 패턴시작
		}
	}
}

void Boss::shellFire()
{
	//대포 발사하기
	cannonFireTimer = cannonFireTimer + Time::deltaTime;

	if (cannonFireTimer >= cannonFireDelay)
	{
		//자식대포 찾기
		string name[2] = { "대포1", "대포2" };

		for (int i = 0; i < 2; i++)
		{
			if (cannonFire[i][cannonFireIndex] == true)
			{
				Cannon* cannon = (Cannon*)find(name[i]);

				if (cannon != nullptr)
				{
					cannon->onFire();
				}
			}
		}

		cannonFireTimer = 0;
		cannonFireIndex++;

		if (cannonFireIndex >= MAX_CANNON_FIRE)
		{
			cannonFireIndex = 0;
		}
	}
}

void Boss::onChildDestroyed()
{
	childCount++;

	cout << "소멸된 자식객체 갯수 " << childCount <<  endl;

	//점수 올리기//
	GameManager::addScore(15);

	//if (childCount == 25)
	if (childCount == 25)
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

		//보스가..죽었음 게임매니저 공유 변수에..표시
		//GameManager::setBossDead();

		//플레이어를 찾아서..보스가 죽었음을..직접 알려줌
		Player * player =(Player *) ObjectManager::find("플레이어");

		if (player != nullptr)
		{
			player->onBossDestroyed();
		}
		else {
			cout << "===플레이어 객체를 찾지 못함===" << endl;
		}
	}
}