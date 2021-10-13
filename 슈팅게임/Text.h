#pragma once

//��Ʈ ���..��Ŭ��� �ϱ�//
#include <ft2build.h>
#include <freetype/freetype.h>

#include "GameObject.h"

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face    face;
public:
	Text(float px, float py);
	~Text();

	void start();	
	void draw();
};
