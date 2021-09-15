#include "framework.h"

Boss::Boss(float px, float py) :Sprite("", "", true, px, py)
{}

Boss::~Boss()
{}

void Boss::start()
{
	//���ߵ��� ���� ����
	setImage("Asset/����.bmp", 0, 0, 493, 206);

	//���ߵ� ����
	//setImage("Asset/����.bmp", 0, 613, 385, 182);

	//**************���� �ڽİ�ü �߰��ϱ�***************//

	//�����緯 �ڽİ�ü
	addChildObject(new Propeller(63,  41), 0);
	addChildObject(new Propeller(111, 41), 0);
	addChildObject(new Propeller(159, 41), 0);

	addChildObject(new Propeller(302, 41), 0);
	addChildObject(new Propeller(350, 41), 0);
	addChildObject(new Propeller(398, 41), 0);

	//���� �ڽİ�ü
	addChildObject(new Wing(298, 425, 30, 18,     256, 97), 0);  //������ ù��°
	addChildObject(new Wing(329, 426, 32, 16,     302, 94), 0);  //������ �ι�°
}