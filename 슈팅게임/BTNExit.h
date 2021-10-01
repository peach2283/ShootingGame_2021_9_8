#pragma once

#include "Button.h"

class BTNExit : public Button
{
private:
public:
	BTNExit(float px, float py);
	~BTNExit();

	void start();

	//클릭이벤트..오버라이딩//
	void onClick();
};