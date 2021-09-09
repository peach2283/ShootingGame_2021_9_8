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

	//Box2D �浹ü(Collider) �߰��ϱ�//
	vector<BoxCollider2D *> boxCollider;

	//���� ��� ǥ��//
	bool dead;  //true (dead������), false(dead���¾ƴ�)

	//�ڽİ�ü..�߰��ϱ�//
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

	//�浹ü �߰��ϱ�//
	void addBoxCollider2D(float x, float y, float width, float height);

	//�ڽ� ���ӿ�����Ʈ..�߰�/���� �ϱ�//
	void addChildObject(GameObject* o, int layer);
	void delChildObject(GameObject* o);

	//�浹ü ��ȯ�ϱ�
	vector<BoxCollider2D*> getBoxCollider2D();

	//�浹������...�˷��ִ� �Լ�(�浹 �̺�Ʈ �Լ�)//
	virtual void onTriggerStay(GameObject * other);
	virtual void onDestroy();

	//�̸�����..�ڽİ�ü ã��
	GameObject* find(string name);
};