#pragma once

class Scene
{
private:
public:
	Scene();
	virtual ~Scene();

	virtual void load();    //��(��) �ε�
	void unload();			//��(��) ��ε�

	void run();     //��(��) ����
};
