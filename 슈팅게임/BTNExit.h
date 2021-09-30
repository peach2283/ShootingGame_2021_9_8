#pragma once

#include "Button.h"

class BTNExit : public Button
{
private:
public:
	BTNExit(float px, float py);
	~BTNExit();

	void start();
};