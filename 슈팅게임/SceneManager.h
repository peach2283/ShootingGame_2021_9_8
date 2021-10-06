#pragma once

#include "Scene.h"
#include "TitleScene.h"

class SceneManager
{
private:
	static Scene* scene[2];
	static int activeSceneIndex;

public:
	static void init();
	static void run();
	static void unload();

	//씬전환 함수//
	static void loadScene(string name);

};