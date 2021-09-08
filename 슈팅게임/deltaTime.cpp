#include "framework.h"

float Time::currTime = 0;
float Time::prevTime = 0;
float Time::deltaTime= 0;

void Time::init()
{
	currTime = GetTickCount() / 1000.0f;  //����   ������ �ð�
	prevTime = currTime;                 //������ ������ �ð�
	deltaTime = 0;                         //���� �ð�����... �����ð��� �� �ð���
}

void Time::update()
{
	currTime = GetTickCount() / 1000.0f;  //���� ������ �ð�		
	deltaTime = currTime - prevTime;       //��ŸŸ�� ���ϱ�
	prevTime = currTime;                  //������ �ݺ�����..�����ð�����..����ϱ� ���ؼ�..�����ð����� ������
}