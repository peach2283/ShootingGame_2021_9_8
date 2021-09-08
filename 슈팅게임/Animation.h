#pragma once

#include "GameObject.h"
#include "BMP.h"

#include <vector>
using namespace std;

class Animation : public GameObject
{
private:
	//�̹��� ���� �迭//
	vector<Image> image[10];

	int index;  //�ִϸ��̼� �̹��� �ε���
	int id;     //�ִϸ��̼� Ŭ��(clip) ���̵�

	//�̹���..Ÿ�̸�(�ִϸ��̼� �ӵ� ����)//
	float imageTimer;
	float imageDelay;

public:
	Animation(string tag, string name, bool active, float px, float py);
	~Animation();

	void draw();

	void addImage(const char* fileName, int x, int y, int width, int height, int clipId);
	void addImage(const char* fileName, int clipId);

	void setClipId(int clipId);
	void setImageDelay(float delay);

	//�ִϸ��̼� �̺�Ʈ �Լ� �߰��ϱ�//
	virtual void onAnimationEnd();
};