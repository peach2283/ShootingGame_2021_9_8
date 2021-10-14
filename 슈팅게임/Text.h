#pragma once

//폰트 헤더..인클루드 하기//
#include <ft2build.h>
#include <freetype/freetype.h>

#include "GameObject.h"

class Text : public GameObject
{
private:
	FT_Library library;
	FT_Face    face;

	wstring text    = L"";
	unsigned char r = 0, g = 0, b = 0;
	int size        = 14;

public:
	Text(float px, float py);
	~Text();

	void start();	
	void draw();

	void setText(wstring text);
	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void setSize(int size);
	void setFontFamily(const char* fileName);
};
