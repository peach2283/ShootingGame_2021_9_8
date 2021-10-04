#pragma once

#include "GameObject.h"

class UIManager : public GameObject
{
private:
public:
	UIManager();
	~UIManager();

	void start();
	void update();
};
