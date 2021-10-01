#pragma once

#include "Button.h"

class BTNPause : public Button
{
private:
public:
	BTNPause(float px, float py);
	~BTNPause();

	void start();
	void onClick();
};