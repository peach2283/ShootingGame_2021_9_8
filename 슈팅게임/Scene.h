#pragma once

class Scene
{
private:
	string name;

public:
	Scene(string name);
	virtual ~Scene();

	virtual void load();    //��(��) �ε�
	void unload();			//��(��) ��ε�

	void run();     //��(��) ����

	//�� �̸� ����//
	string getName();
};
