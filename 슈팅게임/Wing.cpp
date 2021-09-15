#include "framework.h"

Wing::Wing(int imgX, int imgY, int imgW, int imgH,  float px, float py) : Sprite("","",true, px, py)
{
	this->imgX = imgX;
	this->imgY = imgY;
	this->imgW = imgW;
	this->imgH = imgH;
}

Wing::~Wing()
{}

void Wing::start()
{
	setImage("Asset/º¸½º.bmp", imgX, imgY, imgW, imgH);
}