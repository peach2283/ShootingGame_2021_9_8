#pragma once

#define ENEMY_MAX 20

class GameManager
{
private:
	static int  enemyCount;
	
	static bool dropLaserItem[ENEMY_MAX];
	static bool dropBombItem [ENEMY_MAX];

	static int   playerCount; //�÷��̾� ī��Ʈ
	static float playerHp;    //�÷��̾� ü��

	static bool bossDead;    //true - ������ ����, false- ������ ���� ����

	static bool isPause;     //true(�Ͻ�����), false(������)

	static int bombCount;    //��ź ī��Ʈ

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

	//�÷��̾� ü�� �����ϱ�
	static void applyDamage(float damage);

	//�÷��̾� ü�� ��������
	static float getPlayerHp();

	//�÷��̾� ī��Ʈ ��������
	static int getPlayerCount();

	//��ź ī��Ʈ ����/����/ ��������
	static void addBomb();  //��ź����
	static void subBmob();  //��ź����
	static int  getBombCount(); //��Ÿī��Ʈ ��������

	//�������� ���� ����..����/����
	static bool getBossDead();
	static void setBossDead();

	//�Ͻ����� ����(isPause)����/����
	static bool getPause();
	static void setPause(bool pause);

	//���ӸŴ���..����Ÿ..�����ϱ�//
	static void reset();
};