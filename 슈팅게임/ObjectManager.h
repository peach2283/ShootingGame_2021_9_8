#pragma once

#include <vector>
#include "GameObject.h"

#define MAX_LAYER 10
#define UI_LAYER  6

class ObjectManager
{
private:
	static vector<GameObject*> gameObject[MAX_LAYER]; //게임오브젝트..레이어 배열

public:

	//stl vector에 인스턴트(객체) 추가/삭제 함수//
	static void instantiate(GameObject* o, int layer);
	static void destroy(GameObject* o);

	//목록에..추가된 객체..업데이트 함수//
	static void update();

	//업데이타 이후에..충돌검사 함수//
	static void checkCollision();
	static void checkObjectCollision(GameObject* objI, GameObject* objJ);

	//삭제표시된..객체 삭제하기//
	static void clearDead();

	//목록체..추가된 객체..그리기 함수//
	static void draw();

	//목록에..추가된 객체..모두 제거 함수//
	static void clear();

	//오브젝트..목록에서..이름으로 객체 찾기
	static GameObject* find(string name);
};