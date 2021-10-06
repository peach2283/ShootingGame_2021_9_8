#include "framework.h"

Scene* SceneManager::scene[2]	   = { new TitleScene(), new GameScene() };
int SceneManager::activeSceneIndex = 0;

void SceneManager::init()
{
	scene[activeSceneIndex]->load();
}

void SceneManager::run()
{
	scene[activeSceneIndex]->run();
}

void SceneManager::unload()
{
	scene[activeSceneIndex]->unload();
}

void SceneManager::loadScene(string name)
{
	for (int i = 0; i < 2; i++)
	{
		if (scene[i]->getName() == name)
		{
			//이전씬 언로드하기//
			scene[activeSceneIndex]->unload();

			activeSceneIndex = i;  //전환되는 씬 인덱스

			//전환되는 씬 로드하기
			scene[activeSceneIndex]->load();

			break; 
		}
	}
}