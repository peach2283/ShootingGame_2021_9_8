#include "framework.h"

Propeller::Propeller(float px, float py) : Animation("", "", true, px, py)
{}

Propeller::~Propeller()
{}

void Propeller::start()
{
	//피해없는 프로펠러 - 0 //
	addImage("Asset/보스.bmp", 7 + 34 * 0, 439, 32, 12, 0);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 439, 32, 12, 0);

	//피해입은 프로펠러 - 1//
	addImage("Asset/보스.bmp", 7 + 34 * 0, 455, 32, 52, 1);
	addImage("Asset/보스.bmp", 7 + 34 * 1, 455, 32, 52, 1);

	setImageDelay(0.1);	
}