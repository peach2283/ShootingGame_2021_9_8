#include "framework.h"

ShipExp::ShipExp(float px, float py):Animation("","", true, px, py)
{}

ShipExp::~ShipExp()
{}

void ShipExp::start()
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			addImage("Asset/Æø¹ßÈ¿°ú.bmp", 0+col * (128 + 1), 605+row * (128+1), 128, 128, 0);
		}
	}

	setImageDelay(0.02);
}

void ShipExp::onAnimationEnd()
{
	destroy(this);
}