#include "framework.h"

Wing::Wing(int imgX, int imgY, int imgW, int imgH,  float px, float py) 
	 : Wing(imgX, imgY, imgW, imgH, 0, 0, imgW, imgH, px, py)
{
}

Wing::Wing(int imgX, int imgY, int imgW, int imgH, float colX, float colY, float colW, float colH, float px, float py)
	: Sprite("","", true, px, py)
{
	this->imgX = imgX;
	this->imgY = imgY;
	this->imgW = imgW;
	this->imgH = imgH;

	this->colX = colX;
	this->colY = colY;
	this->colW = colW;
	this->colH = colH;

	this->hp = 100;
}

Wing::~Wing()
{}

void Wing::start()
{
	setImage("Asset/����.bmp", imgX, imgY, imgW, imgH);
	addBoxCollider2D(colX, colY, colW, colH);
}

void Wing::onTriggerStay(GameObject* other)
{
	string tag = other->getTag();

	if (tag == "�÷��̾����")
	{
		//�÷��̾� ������..����ȿ��//
		float ex = other->getPx();
		float ey = other->getPy();

		instantiate(new PlayerLaserExp(ex - 15, ey - 15), 1);

		//�÷��̾� ������..�����ϱ�//
		destroy(other);

		//ü�� ���� �� �ִϸ��̼� ����
		hp = hp - 10;

		if (hp <= 0)
		{
			explode();
		}
	}
	else if (tag == "�÷��̾���ź����")
	{
		explode();
	}
}

void Wing::explode()
{
	//�ڽ�����//
	float px = this->getPx();
	float py = this->getPy();

	instantiate(new ShipExp(px - 50, py - 40), 1);

	//�ڽİ�ü����
	destroy(this);

	//�θ� ������ü��...���ŵǾ����� �˷���
	Boss* boss = (Boss*)getParent();
	boss->onChildDestroyed();
}