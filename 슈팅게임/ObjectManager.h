#pragma once

#include <vector>
#include "GameObject.h"

#define MAX_LAYER 10
#define UI_LAYER  6

class ObjectManager
{
private:
	static vector<GameObject*> gameObject[MAX_LAYER]; //���ӿ�����Ʈ..���̾� �迭

public:

	//stl vector�� �ν���Ʈ(��ü) �߰�/���� �Լ�//
	static void instantiate(GameObject* o, int layer);
	static void destroy(GameObject* o);

	//��Ͽ�..�߰��� ��ü..������Ʈ �Լ�//
	static void update();

	//������Ÿ ���Ŀ�..�浹�˻� �Լ�//
	static void checkCollision();
	static void checkObjectCollision(GameObject* objI, GameObject* objJ);

	//����ǥ�õ�..��ü �����ϱ�//
	static void clearDead();

	//���ü..�߰��� ��ü..�׸��� �Լ�//
	static void draw();

	//��Ͽ�..�߰��� ��ü..��� ���� �Լ�//
	static void clear();

	//������Ʈ..��Ͽ���..�̸����� ��ü ã��
	static GameObject* find(string name);
};