#pragma once

#include "Animation.h"

class Propeller : public Animation
{
private:
public:
	Propeller(float px, float py);
	~Propeller();

	void start();
};