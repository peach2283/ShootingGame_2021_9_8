#pragma once

#include "Scene.h"
#include "TitleScene.h"

class SceneManager
{
private:
	static Scene* scene[3];
	static int activeSceneIndex;
	static int nextSceneIndex;

public:
	static void init();
	static void run();
	static void unload();

	//����ȯ �Լ�//
	static void loadScene(string name);

	//���� ��Ƽ�� �� ��ȯ�Լ�//
	static Scene* getActiveScene();
};