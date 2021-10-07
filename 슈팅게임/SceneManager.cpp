#include "framework.h"

Scene* SceneManager::scene[2]	   = { new TitleScene(), new GameScene() };

int SceneManager::activeSceneIndex = 0;
int SceneManager::nextSceneIndex   =-1;

void SceneManager::init()
{
	scene[activeSceneIndex]->load();
}

void SceneManager::run()
{
	scene[activeSceneIndex]->run();  //업데이트...반복문..중에서..씬 전환발생함

	////씬에서 반복문이..종료된 후...씬전환을 함////
	if (nextSceneIndex != -1)
	{
		//이전씬 언로드하기//
		scene[activeSceneIndex]->unload();

		//전환할 씬 인덱스 변경
		activeSceneIndex = nextSceneIndex;

		//전환되는 씬 로드하기
		scene[activeSceneIndex]->load();

		//씬전환이 완료되었음을 표시
		nextSceneIndex = -1;
	}
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
			nextSceneIndex = i; //전환되는 씬 인덱스를 보관
			break; 
		}
	}
}

Scene* SceneManager::getActiveScene()
{
	return scene[activeSceneIndex];
}