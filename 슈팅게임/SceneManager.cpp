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
			//������ ��ε��ϱ�//
			scene[activeSceneIndex]->unload();

			activeSceneIndex = i;  //��ȯ�Ǵ� �� �ε���

			//��ȯ�Ǵ� �� �ε��ϱ�
			scene[activeSceneIndex]->load();

			break; 
		}
	}
}