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
	scene[activeSceneIndex]->run();  //������Ʈ...�ݺ���..�߿���..�� ��ȯ�߻���

	////������ �ݺ�����..����� ��...����ȯ�� ��////
	if (nextSceneIndex != -1)
	{
		//������ ��ε��ϱ�//
		scene[activeSceneIndex]->unload();

		//��ȯ�� �� �ε��� ����
		activeSceneIndex = nextSceneIndex;

		//��ȯ�Ǵ� �� �ε��ϱ�
		scene[activeSceneIndex]->load();

		//����ȯ�� �Ϸ�Ǿ����� ǥ��
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
			nextSceneIndex = i; //��ȯ�Ǵ� �� �ε����� ����
			break; 
		}
	}
}

Scene* SceneManager::getActiveScene()
{
	return scene[activeSceneIndex];
}