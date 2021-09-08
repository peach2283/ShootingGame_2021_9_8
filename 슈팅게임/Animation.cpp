#include "framework.h"

Animation::Animation(string tag, string name, bool active, float px, float py)
		  :GameObject(tag, name, active, px, py)
{
	this->index = 0;
	this->id	= 0;

	this->imageTimer = 0;
	this->imageDelay = 0.05;	
}

Animation::~Animation()
{
	//�ִϸ��̼�...�̹��� �޸� �����ϱ�//
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < image[i].size(); j++)
		{
			delete[] image[i][j].argb;
		}

		image[i].clear();
	}
}

void Animation::addImage(const char* fileName, int x, int y, int width, int height, int clipId)
{
	Image img;

	Bitmap::readBMP(fileName, x, y, width, height, &img);
	image[clipId].push_back(img);
}

void Animation::addImage(const char* fileName, int clipId)
{
	Image img;

	Bitmap::readBMP(fileName, &img);
	image[clipId].push_back(img);
}

void Animation::draw()
{
	//�ִϸ��̼� �ð� �����ϱ�//
	imageTimer = imageTimer + Time::deltaTime;
	
	float px = getPx();
	float py = getPy();

	Bitmap::drawBMP(px, py, &image[id][index]);

	if (imageTimer >= imageDelay)
	{
		index++;

		if (index >= image[id].size())
		{
			//������..�ִϸ��̼� �̹��� ����//
			onAnimationEnd();  //�ִϸ޴ϼ� ����..�̺�Ʈ..�Լ� ȣ��

			index = 0;
		}

		imageTimer = 0;
	}
}

void Animation::onAnimationEnd()
{}

void Animation::setClipId(int clipId)
{
	this->id = clipId;
}

void Animation::setImageDelay(float delay)
{
	this->imageDelay = delay;
}