#include "framework.h"

Scene::Scene()
{}

Scene::~Scene()
{}

void Scene::load()    //씬(맵)로딩
{
}

void Scene::run()     //씬(맵) 구동
{
    ObjectManager::update();        //매니저 목록(오브젝트 계층구조)의 객체들 업데이트
    ObjectManager::checkCollision();//매니저 목록(오브젝트 계층구조)의 객체들의 업데이트후..충돌검사
    ObjectManager::clearDead();     //삭제 대상으로 표시된 객체들을 모두..제거하기

    ObjectManager::draw();   //매니저 목록(오브젝트 계층구조)의 객체들 그리기
}

void Scene::unload()  //씬(맵)언로딩
{
    ObjectManager::clear();
}