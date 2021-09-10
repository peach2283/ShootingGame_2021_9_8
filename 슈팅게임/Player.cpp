#include "framework.h"

Player::Player(float px, float py) : GameObject("플레이어","", true, px, py)
{	
	this->speed = 200; //플레이어 이동 속력

	this->fireTimer = 0;   //발사타이머
	this->fireDelay = 0.2; //발사대기시간

	this->index = 3;

	this->imageTimer = 0;
	this->imageDelay = 0.1; 

	this->hp = 100;

	this->state       = State::moveUp;
	this->shieldTimer = 3;

	this->laserCount = 0;
}

Player::~Player()
{
	for (int i = 0; i < 7; i++)
	{
		delete[] image[i].argb;
	}
}

void Player::start()
{
	//플레이어 이미지들 ..로드하기//
	Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * 0, 82, 62, 80, &image[0]);
	Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * 1, 82, 62, 80, &image[1]);
	Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * 2, 82, 62, 80, &image[2]);
	Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * 3, 82, 62, 80, &image[3]);
	Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * 4, 82, 62, 80, &image[4]);
	Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * 5, 82, 62, 80, &image[5]);
	Bitmap::readBMP("Asset/팬텀이동2.bmp", 64 * 6, 82, 62, 80, &image[6]);

	//충돌체..추가하기
	addBoxCollider2D(25,  8, 13, 64); //가운데 몸통
	addBoxCollider2D( 9, 43, 44, 14); //가운데 날개

	//자식객체..추가하기//
	addChildObject( new Shield(-10, -10), 1);
}

void Player::update()
{
	switch (state)
	{
		case State::moveUp :
		{
			//위로..이동하기//
			float dist = speed * Time::deltaTime;
			translate(0, -dist);

			//위로 이동 후...플레이 위치가 되면..
			float py = getPy();

			if (py <= 650)
			{
				state = State::control;
			}			
		}
		break;

		case State::control:
		{
			move();		//이동
			fire();		//발사	
			shield();	//방패비활성화			
		}

		break;
	}
}

void Player::draw()
{
	float px = getPx();
	float py = getPy();

	Bitmap::drawBMP(px, py, &image[index]);
}

void Player::shield()
{
	//방패 비활성화 시간측정하기//
	shieldTimer = shieldTimer - Time::deltaTime;

	if (shieldTimer <= 0)
	{
		//방패 자식오브젝트 찾기
		GameObject* o = find("방패");

		if (o != nullptr)
		{
			o->setActive(false); //방패숨김
			///delChildObject(o);
		}
		else {
			cout << "방패를 찾지 못함" << endl;
		}
	}
}

void Player::move()
{
	float dist = speed * Time::deltaTime;  //이동거리 계산하기

	if (Input::getKey("left") == true)
	{
		translate(-dist, 0);

		//플레이어가 왼쪽 화면밖으로..나가지 못하게 하기//
		float px = getPx();

		if (px < -10)
		{
			setPx(-10);
		}

		//플레이어..이미지 인덱스..감소//
		imageTimer = imageTimer + Time::deltaTime;

		if (imageTimer >= imageDelay)
		{
			index--;

			if (index < 0)
			{
				index = 0;
			}

			imageTimer = 0;
		}
	}

	if (Input::getKey("right") == true)
	{
		translate(dist, 0);

		//플레이어가 오른쪽 화면밖으로..나가지 못하게 하기//
		float px = getPx();

		if (px > WIDTH - 54)
		{
			setPx(WIDTH - 54);
		}

		//플레이어..이미지 인덱스..증가//
		imageTimer = imageTimer + Time::deltaTime;

		if (imageTimer >= imageDelay)
		{
			index++;

			if (index > 6)
			{
				index = 6;
			}

			imageTimer = 0;
		}
	}

	if (Input::getKey("left") != true && Input::getKey("right") != true)
	{
		index = 3;
	}

	if (Input::getKey("up") == true)
	{
		translate(0, -dist);

		//플레이어가 위쪽 화면밖으로..나가지 못하게 하기//
		float py = getPy();

		if (py < 0)
		{
			setPy(0);
		}
	}

	if (Input::getKey("down") == true)
	{
		translate(0, dist);

		//플레이어가 아래쪽 화면밖으로..나가지 못하게 하기//
		float py = getPy();

		if (py > HEIGHT - 80)
		{
			setPy(HEIGHT - 80);
		}
	}
}

void Player::fire()
{
	//발사하기//
	if (Input::getKey("space") == true)
	{		
		//발사시간 측정하기
		fireTimer = fireTimer + Time::deltaTime;

		if (fireTimer >= fireDelay)
		{
			float px = getPx() + 28;
			float py = getPy() - 20;

			if (laserCount == 0)
			{
				//레이저 한발 발사
				instantiate(new PlayerLaser(px, py), 0);
			}
			else if (laserCount == 1)
			{
				//레이저 두발 발사
				instantiate(new PlayerLaser(px - 5, py), 0);
				instantiate(new PlayerLaser(px + 5, py), 0);
			}
			else if (laserCount == 2)
			{
				//레이저 세발 발사
				instantiate(new PlayerLaser(px - 8, py), 0);
				instantiate(new PlayerLaser(px, py - 10), 0);
				instantiate(new PlayerLaser(px + 8, py), 0);
			}

			fireTimer = 0; //타이머 리셋하기
		}
	}
}

void Player::onTriggerStay(GameObject* other)
{	
	string tag = other->getTag();

	if (tag == "적기")
	{
		explode();
	}
	else if (tag == "적기총알")
	{
		//플레이어 체력 감소
		hp = hp - 10;

		//적기 총알제하기
		destroy(other);

		//총알 폭발 효과
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new EnemyBulletExp(ex-10, ey), 1);

		//플레이어 폭발 및 제거
		if (hp <= 0)
		{
			//explode();
		}
	}
	else if (tag == "레이저아이템")
	{
		if (laserCount < 2)
		{
			//레이저발사갯수 늘리기//
			laserCount++;
		}

		//레이저아이템 삭제//
		destroy(other);
	}	
}

void Player::explode()
{
	//플레이어 폭발 및 제거//
	float px = getPx();
	float py = getPy();

	instantiate(new ShipExp(px - 20, py - 10), 1);  //플레이어 폭발 효과
	destroy(this);									//플레이어 제거

	//임시로..플레이어 리스폰하기//
	ObjectManager::instantiate(new Player(240 - 40, HEIGHT + 50), 0);
}