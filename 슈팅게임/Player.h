#pragma once

#include "Sprite.h"

class Player : public GameObject
{
	enum class State {moveUp=0 , control=1};

private:
	float speed;	 //이동 속력
	
	float fireTimer; //발사시간 측정하기
	float fireDelay; //발사대시 시간
	
	Image image[7]; //플레이어 이미지들
	int   index;    //플레이어 이미지 인덱스

	float imageTimer; //이미지 변경...측정
	float imageDelay; //이미지 변경..대기 시간

	float hp;  

	State state;

	float shieldTimer; //보호방패 지속시간(control 이후)
	int   laserCount;  //발사되는 레이저 갯수 (0 - 한번, 1 - 두발 , 2 - 세발)

public:
	Player(float px, float py);
	~Player();

	void start();
	void update();
	void draw();

	//플레이어..키입력..이동 함수//
	void move();

	//플레이어..레이어..폭탄 발사 함수//
	void fire();

	//플레이어..방패 숨기기
	void shield();

	//충돌이벤트..처리하기(오버라이딩)//
	void onTriggerStay(GameObject* other);

	//플레이어 폭발 함수//
	void explode();
};
