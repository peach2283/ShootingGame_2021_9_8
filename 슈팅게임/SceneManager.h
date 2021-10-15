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

	//씬전환 함수//
	static void loadScene(string name);

	//현재 액티브 씬 반환함수//
	static Scene* getActiveScene();
};