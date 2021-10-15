#pragma once

#include "GameObject.h"
#include "BMP.h"
#include "Text.h"

class HPBar : public GameObject
{
private:
	Image BG;
	Image Bar;

	Text* text;

	float fillAmount;

public:
	HPBar(float px, float py);
	~HPBar();

	void start();
	void draw();

	void setFillAmount(float fillAmount);
	void setText(wstring text);
};
