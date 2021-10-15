
#include "framework.h"

GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag	 = tag;
	this->name	 = name;
	this->active = active;

	this->px = px;
	this->py = py;	

	this->dead   = false;   //생성자에서..게임오브젝트가 dead가 아님
	this->parent = nullptr; //생성자에서..부모게임오브젝트가 없음으로..초기화(addChildObject에서 부모포인터 지정)
}

GameObject::~GameObject()
{
	//총돌체...제거하기//
	for (int i = 0; i < boxCollider.size(); i++)
	{
		delete boxCollider[i];
	}

	boxCollider.clear();
}

string GameObject::getTag()
{
	return tag;
}

string GameObject::getName()
{
	return name;
}

bool  GameObject::getActive()
{
	return active;
}

float GameObject::getPx()
{
	return px;
}

float GameObject::getPy()
{
	return py;
}

bool GameObject::getDead()
{
	return dead;
}

void GameObject::setTag(string tag)
{
	this->tag = tag;
}

void GameObject::setName(string name)
{
	this->name = name;
}

void GameObject::setActive(bool active)
{
	this->active = active;

	//자식객체목록에..활성화 적용하기//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->setActive(active);
	}
}

void GameObject::setPx(float px)
{
	//게임오브젝트의..새로운 좌표까지의 이동량//
	float dx = px - this->px;

	//게임오브젝트...x좌표 지정//
	this->px = px;

	//충돌체...x 위치..변경..적용하기//
	for (int i = 0; i < boxCollider.size(); i++)
	{
		boxCollider[i]->translate(dx, 0);
	}

	//자식객체...x 위치 변경 적용하기//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(dx, 0);
	}
}

void GameObject::setPy(float py)
{
	//게임오브젝트의..새로운 좌표까지의 이동량//
	float dy = py - this->py;

	//게임오브젝트...y좌표 지정//
	this->py = py;

	//충돌체...y 위치..변경..적용하기//
	for(int i=0 ; i < boxCollider.size() ; i++)
	{
		boxCollider[i]->translate(0, dy);
	}

	//자식객체...y 위치 변경 적용하기//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(0, dy);
	}
}

void GameObject::setDead(bool dead)
{
	this->dead = dead;

	//destroy이벤트 발생시킴//
	if (dead == true)
	{
		onDestroy();
	}

	//자식객체..제거시키기//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->setDead(dead);
	}

	//자식목록 클리어하기
	childObject.clear();
}

void GameObject::start()
{}

void GameObject::update()
{}

void GameObject::draw()
{}

void GameObject::translate(float x, float y)
{
	//게임오브젝트..이동시키기//
	px = px + x;
	py = py + y;

	//충돌체..이동시키기//
	for(int i=0 ; i < boxCollider.size() ; i++)
	{
		boxCollider[i]->translate(x, y);
	}

	//자식객체..이동시키기//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(x, y);
	}
}

GameObject * GameObject::instantiate(GameObject* o, int layer)
{
	ObjectManager::instantiate(o, layer);
	return o;  //인스턴스로..목록에 추가한 객체 반환하기
}

void GameObject::destroy(GameObject* o)
{
	if (o->parent == nullptr)
	{
		ObjectManager::destroy(o);
	}
	else {
		o->parent->delChildObject(o);
	}
}

void GameObject::addBoxCollider2D(float x, float y, float width, float height)
{
	boxCollider.push_back( new BoxCollider2D(x+px, y+py, width, height) );
}
 
GameObject * GameObject::addChildObject(GameObject* o, int layer)
{
	childObject.push_back(o);		
	ObjectManager::instantiate(o, layer);

	//부모객체의 위치가..자식객체의 원점이 되도록..자식 객체를 이동시킴//
	o->translate(px, py);

	//자식객체에..부모객체 포인터..저장하기
	o->parent = this;

	//추가된 자식객체..포인터 반환하기
	return o;
}

void GameObject::delChildObject(GameObject* o)
{
	//자식 목록에서..제거하기//
	for (int i = 0; i < childObject.size(); i++)
	{
		if (childObject[i] == o)
		{			
			childObject.erase( childObject.begin() + i );
			break;
		}
	}

	//오브젝트 매니저에서 삭제하기//
	ObjectManager::destroy(o);
}

vector<BoxCollider2D*> GameObject::getBoxCollider2D()
{
	return boxCollider;
}

void GameObject::onDrawGizmos()
{
	for(int i=0 ; i < boxCollider.size(); i++)
	{
		//충돌체..표시하기 - 충돌체..기즈모//
		float x, y, width, height;
		boxCollider[i]->getBox(x, y, width, height);

		float x0 = x, y0 = y, x1 = x + width, y1 = y + height;
		drawRect(x0, y0, x1, y1, 255, 0, 0);
	}
}

void GameObject::onTriggerStay(GameObject* other)
{}

void GameObject::onDestroy()
{}

GameObject* GameObject::find(string name)
{
	for (int i = 0; i < childObject.size(); i++)
	{
		if (childObject[i]->getName() == name)
		{
			return childObject[i];
		}
	}

	//해당 자식오브젝트를 찾지 못한경우//
	return nullptr;
}

GameObject* GameObject::getParent()
{
	return parent;
}