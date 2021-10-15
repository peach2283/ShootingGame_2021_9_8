
#include "framework.h"

GameObject::GameObject(string tag, string name, bool active, float px, float py)
{
	this->tag	 = tag;
	this->name	 = name;
	this->active = active;

	this->px = px;
	this->py = py;	

	this->dead   = false;   //�����ڿ���..���ӿ�����Ʈ�� dead�� �ƴ�
	this->parent = nullptr; //�����ڿ���..�θ���ӿ�����Ʈ�� ��������..�ʱ�ȭ(addChildObject���� �θ������� ����)
}

GameObject::~GameObject()
{
	//�ѵ�ü...�����ϱ�//
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

	//�ڽİ�ü��Ͽ�..Ȱ��ȭ �����ϱ�//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->setActive(active);
	}
}

void GameObject::setPx(float px)
{
	//���ӿ�����Ʈ��..���ο� ��ǥ������ �̵���//
	float dx = px - this->px;

	//���ӿ�����Ʈ...x��ǥ ����//
	this->px = px;

	//�浹ü...x ��ġ..����..�����ϱ�//
	for (int i = 0; i < boxCollider.size(); i++)
	{
		boxCollider[i]->translate(dx, 0);
	}

	//�ڽİ�ü...x ��ġ ���� �����ϱ�//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(dx, 0);
	}
}

void GameObject::setPy(float py)
{
	//���ӿ�����Ʈ��..���ο� ��ǥ������ �̵���//
	float dy = py - this->py;

	//���ӿ�����Ʈ...y��ǥ ����//
	this->py = py;

	//�浹ü...y ��ġ..����..�����ϱ�//
	for(int i=0 ; i < boxCollider.size() ; i++)
	{
		boxCollider[i]->translate(0, dy);
	}

	//�ڽİ�ü...y ��ġ ���� �����ϱ�//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(0, dy);
	}
}

void GameObject::setDead(bool dead)
{
	this->dead = dead;

	//destroy�̺�Ʈ �߻���Ŵ//
	if (dead == true)
	{
		onDestroy();
	}

	//�ڽİ�ü..���Ž�Ű��//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->setDead(dead);
	}

	//�ڽĸ�� Ŭ�����ϱ�
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
	//���ӿ�����Ʈ..�̵���Ű��//
	px = px + x;
	py = py + y;

	//�浹ü..�̵���Ű��//
	for(int i=0 ; i < boxCollider.size() ; i++)
	{
		boxCollider[i]->translate(x, y);
	}

	//�ڽİ�ü..�̵���Ű��//
	for (int i = 0; i < childObject.size(); i++)
	{
		childObject[i]->translate(x, y);
	}
}

GameObject * GameObject::instantiate(GameObject* o, int layer)
{
	ObjectManager::instantiate(o, layer);
	return o;  //�ν��Ͻ���..��Ͽ� �߰��� ��ü ��ȯ�ϱ�
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

	//�θ�ü�� ��ġ��..�ڽİ�ü�� ������ �ǵ���..�ڽ� ��ü�� �̵���Ŵ//
	o->translate(px, py);

	//�ڽİ�ü��..�θ�ü ������..�����ϱ�
	o->parent = this;

	//�߰��� �ڽİ�ü..������ ��ȯ�ϱ�
	return o;
}

void GameObject::delChildObject(GameObject* o)
{
	//�ڽ� ��Ͽ���..�����ϱ�//
	for (int i = 0; i < childObject.size(); i++)
	{
		if (childObject[i] == o)
		{			
			childObject.erase( childObject.begin() + i );
			break;
		}
	}

	//������Ʈ �Ŵ������� �����ϱ�//
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
		//�浹ü..ǥ���ϱ� - �浹ü..�����//
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

	//�ش� �ڽĿ�����Ʈ�� ã�� ���Ѱ��//
	return nullptr;
}

GameObject* GameObject::getParent()
{
	return parent;
}