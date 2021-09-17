#pragma once

#include "Sprite.h"

class Wing : public Sprite
{
private:
	int   imgX, imgY, imgW, imgH;  //이미지 좌표
	float colX, colY, colW, colH;  //중도체 좌표

	float hp;

public:	
	Wing(int imgX, int imgY, int imgW, int imgH, float px, float py);
	Wing(int imgX, int imgY, int imgW, int imgH, float colX, float colY, float colW, float colH, float px, float py);

	~Wing();

	void start();
	void onTriggerStay(GameObject* other);

	void explode();
};