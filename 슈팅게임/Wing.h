#pragma once

#include "Sprite.h"

class Wing : public Sprite
{
private:
	int imgX, imgY, imgW, imgH;  //�̹��� ��ǥ

public:
	Wing(int imgX, int imgY, int imgW, int imgH, float px, float py);
	~Wing();

	void start();
};