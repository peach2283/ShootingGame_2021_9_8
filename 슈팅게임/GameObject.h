#pragma once

#include <string>
#include <vector>
#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	string tag;
	string name;
	bool   active;

	float px, py;

	//Box2D 충돌체(Collider) 추가하기//
	vector<BoxCollider2D *> boxCollider;

	//삭제 대상 표시//
	bool dead;  //true (dead상태임), false(dead상태아님)

	//자식객체..추가하기//
	vector<GameObject* > childObject;

public:
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	string getTag();
	string getName();
	bool   getActive();
	float  getPx();
	float  getPy();
	bool   getDead();

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);
	void setPx(float px);
	void setPy(float py);
	void setDead(bool deal);

	virtual void start();
	virtual void update();
	virtual void draw();
	virtual void onDrawGizmos();

	void translate(float x, float y);

	void instantiate(GameObject* o, int layer);
	void destroy(GameObject* o);

	//충돌체 추가하기//
	void addBoxCollider2D(float x, float y, float width, float height);

	//자식 게임오브젝트..추가/삭제 하기//
	void addChildObject(GameObject* o, int layer);
	void delChildObject(GameObject* o);

	//충돌체 반환하기
	vector<BoxCollider2D*> getBoxCollider2D();

	//충돌했음을...알려주는 함수(충돌 이벤트 함수)//
	virtual void onTriggerStay(GameObject * other);
	virtual void onDestroy();

	//이름으로..자식객체 찾기
	GameObject* find(string name);
};