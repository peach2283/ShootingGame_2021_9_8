#include "framework.h"

GameScene::GameScene() : Scene("GameScene")
{}

GameScene::~GameScene()
{}

void GameScene::load()
{
    //...��� �� �ʱ� ��ü..�߰��ϱ�//
    ObjectManager::instantiate(new GameBG(), 0);
    ObjectManager::instantiate(new EnemySpawner(WIDTH / 2, 10), 0);

    //�÷��̾� �����ϱ�//
    GameManager::playerSpawn(240 - 40, HEIGHT + 50);

    //UIManager �߰��ϱ�//
    ObjectManager::instantiate(new UIManager(), 0);
}