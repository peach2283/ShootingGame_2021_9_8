#pragma once

typedef unsigned int uint;

struct Image
{
	//�ε��̹��� ������
	int width;	 //�̹��� ���� 
	int height;	 //�̹��� ����
	uint* argb;  //�̹��� �ȼ�����Ÿ ����(�����Ҵ�)�迭
};

class Bitmap
{
private:
public:
	static void readBMP(const char* fileName, Image* img);
	static void readBMP(const char* fileName, int x, int y, int width, int height,  Image* img);

	static void drawBMP(float px, float py, Image* img);
	static void drawBMP(float px, float py, float fillAmount, Image* img);
};