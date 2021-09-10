#pragma once

#include "Sprite.h"

class Player : public GameObject
{
	enum class State {moveUp=0 , control=1};

private:
	float speed;	 //�̵� �ӷ�
	
	float fireTimer; //�߻�ð� �����ϱ�
	float fireDelay; //�߻��� �ð�
	
	Image image[7]; //�÷��̾� �̹�����
	int   index;    //�÷��̾� �̹��� �ε���

	float imageTimer; //�̹��� ����...����
	float imageDelay; //�̹��� ����..��� �ð�

	float hp;  

	State state;

	float shieldTimer; //��ȣ���� ���ӽð�(control ����)
	int   laserCount;  //�߻�Ǵ� ������ ���� (0 - �ѹ�, 1 - �ι� , 2 - ����)

public:
	Player(float px, float py);
	~Player();

	void start();
	void update();
	void draw();

	//�÷��̾�..Ű�Է�..�̵� �Լ�//
	void move();

	//�÷��̾�..���̾�..��ź �߻� �Լ�//
	void fire();

	//�÷��̾�..���� �����
	void shield();

	//�浹�̺�Ʈ..ó���ϱ�(�������̵�)//
	void onTriggerStay(GameObject* other);

	//�÷��̾� ���� �Լ�//
	void explode();
};
