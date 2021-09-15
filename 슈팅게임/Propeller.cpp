#include "framework.h"

Propeller::Propeller(float px, float py) : Animation("", "", true, px, py)
{}

Propeller::~Propeller()
{}

void Propeller::start()
{
	//���ؾ��� �����緯 - 0 //
	addImage("Asset/����.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/����.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//�������� �����緯 - 1//
	addImage("Asset/����.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/����.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	setImageDelay(0.1);	
}