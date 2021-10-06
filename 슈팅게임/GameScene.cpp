#include "framework.h"

GameScene::GameScene() : Scene("GameScene")
{}

GameScene::~GameScene()
{}

void GameScene::load()
{
    //...배경 및 초기 객체..추가하기//
    ObjectManager::instantiate(new GameBG(), 0);
    ObjectManager::instantiate(new EnemySpawner(WIDTH / 2, 10), 0);

    //플레이어 스폰하기//
    GameManager::playerSpawn(240 - 40, HEIGHT + 50);

    //UIManager 추가하기//
    ObjectManager::instantiate(new UIManager(), 0);
}