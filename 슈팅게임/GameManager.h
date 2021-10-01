#pragma once

#define ENEMY_MAX 20

class GameManager
{
private:
	static int  enemyCount;
	
	static bool dropLaserItem[ENEMY_MAX];
	static bool dropBombItem [ENEMY_MAX];

	static int  playerCount;
	static bool bossDead;    //true - ������ ����, false- ������ ���� ����

	static bool isPause;     //true(�Ͻ�����), false(������)

public:

	//����ī��Ʈ..���� ���� �Լ�//
	static void addEnemy(); //��������..���� ī��Ʈ ����
	static void subEnemy(); //�������� ����..���� ī��Ʈ ����

	//����ī��Ʈ ����//
	static int getEnemyCount(); //����ī��Ʈ�� ��������

	//���� �ִ� ���� ����
	static int getEnemyMax();

	//���Ⱑ ������������/��ź������ �������� ��������//
	static bool doDropLaserItem(int num);
	static bool doDropBombItem (int num);

	//�÷��̾� �����ϱ�
	static void playerSpawn(float px, float py);

	//�������� ���� ����..����/����
	static bool getBossDead();
	static void setBossDead();

	//�Ͻ����� ����(isPause)����/����
	static bool getPause();
	static void setPause(bool pause);
};