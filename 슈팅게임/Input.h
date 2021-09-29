#pragma once

#include <string>

using namespace std;

class Input
{
	enum class State { keyUpRep = 0, keyDown = 1, keyDownRep = 2, keyUp = 3 }; //0-���� ����, 1-�ѹ� ���� 2-������ ����, 3-�ѹ�����

private:
	static State state[9];
	static int key[9];
	static string name[9];

public:

	static void update();  //Ű���� ������Ʈ

	//Ű�˻� �Լ�
	static bool getKeyDown(string keyName);
	static bool getKeyUp  (string keyName);
	static bool getKey    (string keyName);

	//���콺��ư �˻� �Լ�
	static bool getMouseButtonDown(int id);  //id 0 �� ���ʹ�ư, 1 �� ������ ��ư 2 �� �����ư
	static bool getMouseButtonUp(int id);
	static bool getMouseButton(int id);
};