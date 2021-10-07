#pragma once

#include "GameObject.h"
#include "BMP.h"

class HPBar : public GameObject
{
private:
	Image BG;
	Image Bar;

	float fillAmount;

public:
	HPBar(float px, float py);
	~HPBar();

	void start();
	void draw();

	void setFillAmount(float fillAmount);
};
