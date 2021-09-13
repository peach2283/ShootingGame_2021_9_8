#include "framework.h"

int Enemy::Num = 0;

Enemy::Enemy(float px, float py) : Animation("적기","",true, px, py)
{
	this->speed		= 50;
	this->fallSpeed = 200;

	this->state = State::moveDown;

	this->fireTimer = 0;
	this->fireDelay = 1;

	this->hp	   = 100;
	this->lifeTime = 5;
}

Enemy::~Enemy()
{}

void Enemy::start()
{
	/*************************[피해없는 애니메이션******************/
	addImage("Asset/적기.bmp", 1 + 200 * 0, 281, 190, 137, 0);
	addImage("Asset/적기.bmp", 1 + 200 * 1, 281, 190, 137, 0);
	/**************************************************************/

	/*************************[중간정도 피해 애니메이션**************/
	addImage("Asset/적기.bmp", 1 + 200 * 0, 141, 190, 137, 1);
	addImage("Asset/적기.bmp", 1 + 200 * 1, 141, 190, 137, 1);
	addImage("Asset/적기.bmp", 1 + 200 * 2, 141, 190, 137, 1);
	addImage("Asset/적기.bmp", 1 + 200 * 3, 141, 190, 137, 1);
	/***************************************************************/

	/************************[많은 피해 애니메이션]*******************/
	addImage("Asset/적기.bmp", 1 + 200 * 0, 1, 190, 137, 2);
	addImage("Asset/적기.bmp", 1 + 200 * 1, 1, 190, 137, 2);
	addImage("Asset/적기.bmp", 1 + 200 * 2, 1, 190, 137, 2);
	addImage("Asset/적기.bmp", 1 + 200 * 3, 1, 190, 137, 2);
	/***************************************************************/

	//애니메이션 클립 변경하기//
	setClipId(0);

	//충돌체..추가하기//
	addBoxCollider2D(67, 10, 56, 13 );  //꼬리날개 
	addBoxCollider2D(88, 23, 14, 114);  //가운데 몸통
	addBoxCollider2D( 4, 91, 182,14 );  //가운데 날개

	//좌우이동 랜덤위치
	hMovePos = Random::Range(50, 150);

	//객체번호가져오기
	num = Num; //객체개별번호
	Num++;     //공유번호 증가
}

void Enemy::update()
{
	//적기 이동 스테이트 머신//
	/***********************/
	switch (state)
	{
		case State::moveDown:
		{
			float dist = speed * Time::deltaTime;
			translate(0, dist);

			int py = getPy();

			if (py >= hMovePos)
			{
				State dir[2] = {State::moveLeft, State::moveRight};
				state = dir[ Random::Range(0,1) ];
			}
		}
		break;

		case State::moveLeft:
		{
			float dist = speed * Time::deltaTime;
			translate(-dist, 0);

			int px = getPx();

			if (px <= 0)
			{
				state = State::moveRight;
			}

		}
		break;

		case State::moveRight:
		{
			float dist = speed * Time::deltaTime;
			translate(dist, 0);

			int px = getPx();

			if (px >= WIDTH - 190)
			{
				state = State::moveLeft;
			}
		}
		break;

		case State::fall:
		{
			//추락이동//
			float dist = fallSpeed * Time::deltaTime;
			translate(0, dist);			

			//라이프 타임//
			lifeTime = lifeTime - Time::deltaTime;

			if (lifeTime <= 0)
			{
				destroy(this);					
			}
		}
		break;
	}
	/******************************/

	//적기 블릿 발사//
	fireTimer = fireTimer + Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float px = getPx();
		float py = getPy();

		instantiate(new EnemyBullet(px+86, py+130), 0);

		fireTimer = 0;
	}
}

void Enemy::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "플레이어레이저")
	{
		hp = hp - 10;
		
		//플레이어 레이저..폭발효과//
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new PlayerLaserExp(ex-15, ey-15), 1);

		//플레이어 레이저..제거하기//
		destroy(other);

		//적기 체력 출력
		//cout << "적기 체력 " << hp << endl;

		//체력감소에 따라서..애니메이션 변경 및 폭발//
		if (70 < hp && hp <= 100)
		{
			setClipId(0);
		}
		else if (40 < hp && hp <= 70)
		{
			setClipId(1);
		}
		else if (0 < hp && hp <= 40)
		{
			setClipId(2);
			state = State::fall;  //추락상태로..전이

		}else  if (hp <= 0)
		{
			float px = this->getPx();
			float py = this->getPy();

			instantiate(new ShipExp(px+30, py+20), 1); //적기폭발효과
			destroy(this);						       //적기제거

			//레이저아이템..생성패턴(배열)사용하기
			if (GameManager::doDropLaserItem(num) == true)
			{
				//레이저아이템 생성//
				instantiate(new LaserItem(px + 88, py + 50), 0);
			}

			//레이저아이템 생성확률
			/***********************
			int p = Random::Range(0, 32767);

			if (p < 32767/2)
			{
				//레이저아이템 생성//
				instantiate(new LaserItem(px + 88, py + 50), 0);
			}
			**************************/
		}
	}
	else if (tag == "방패" || tag == "플레이어폭탄폭발")
	{
		//적기 폭발 효과도..필요하면...이동할수 있음//

		//레이저아이템..생성패턴(배열)사용하기
		if (GameManager::doDropLaserItem(num) == true)
		{
			float px = this->getPx();
			float py = this->getPy();

			//레이저아이템 생성//
			instantiate(new LaserItem(px + 88, py + 50), 0);
		}
	}
}

void Enemy::onDestroy()
{
	GameManager::subEnemy();  //적기카운트 감소
}