#pragma once

class Scene
{
private:
	string name;

public:
	Scene(string name);
	virtual ~Scene();

	virtual void load();    //¾À(¸Ê) ·Îµù
	void unload();			//¾À(¸Ê) ¾ð·Îµù

	void run();     //¾À(¸Ê) ±¸µ¿

	//¾À ÀÌ¸§ °ÔÅÍ//
	string getName();
};
