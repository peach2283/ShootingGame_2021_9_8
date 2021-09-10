#pragma once

#define ENEMY_MAX 20

class GameManager
{
private:
	static int  enemyCount;
	static bool dropLaserItem[ENEMY_MAX];
public:

	//����ī��Ʈ..���� ���� �Լ�//
	static void addEnemy(); //��������..���� ī��Ʈ ����
	static void subEnemy(); //�������� ����..���� ī��Ʈ ����

	//����ī��Ʈ ����//
	static int getEnemyCount(); //����ī��Ʈ�� ��������

	//���� �ִ� ���� ����
	static int getEnemyMax();

	//���Ⱑ ������������ �������� ��������//
	static bool doDropLaserItem(int num);
};