#include "framework.h"

Scene::Scene()
{}

Scene::~Scene()
{}

void Scene::load()    //��(��)�ε�
{
}

void Scene::run()     //��(��) ����
{
    ObjectManager::update();        //�Ŵ��� ���(������Ʈ ��������)�� ��ü�� ������Ʈ
    ObjectManager::checkCollision();//�Ŵ��� ���(������Ʈ ��������)�� ��ü���� ������Ʈ��..�浹�˻�
    ObjectManager::clearDead();     //���� ������� ǥ�õ� ��ü���� ���..�����ϱ�

    ObjectManager::draw();   //�Ŵ��� ���(������Ʈ ��������)�� ��ü�� �׸���
}

void Scene::unload()  //��(��)��ε�
{
    ObjectManager::clear();
}