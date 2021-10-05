#pragma once

class Scene
{
private:
public:
	Scene();
	virtual ~Scene();

	virtual void load();    //¾À(¸Ê) ·Îµù
	void unload();			//¾À(¸Ê) ¾ð·Îµù

	void run();     //¾À(¸Ê) ±¸µ¿
};
