#pragma once

class GameManager
{
private:
	static int enemyCount;
public:

	//����ī��Ʈ..���� ���� �Լ�//
	static void addEnemy(); //��������..���� ī��Ʈ ����
	static void subEnemy(); //�������� ����..���� ī��Ʈ ����

	//����ī��Ʈ ����//
	static int getEnemyCount(); //����ī��Ʈ�� ��������
};