#include "framework.h"

vector<GameObject*> ObjectManager::gameObject[MAX_LAYER];

void ObjectManager::instantiate(GameObject* o, int layer)
{
	gameObject[layer].push_back(o);
	o->start();
}

void ObjectManager::destroy(GameObject* o)
{
	//�浹�˻���� ����� ������..������ �� �ֵ���...����...���� ǥ�ø���//
	o->setDead(true);
}

void ObjectManager::update()
{
	//��ü�� ������Ʈ(�̵�, �߻�)//
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			gameObject[layer][i]->update();
		}
	}
}

void ObjectManager::clearDead()
{
	//�浹 �˻� ���Ŀ�...���� ǥ�� ������Ʈ�� �����ϱ�//
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			if (gameObject[layer][i]->getDead() == true)
			{
				delete gameObject[layer][i];							//��ü ����
				gameObject[layer].erase(gameObject[layer].begin() + i); //stl vector�� �ּ� ���� ���� ����
				
				i--;  //���� ����ε����� �ǳʲ�°��� �����ϱ� ���ؼ�..�ε����� ���ҽ�Ŵ
			}
		}
	}
}

void ObjectManager::checkCollision()
{
	/***************************************************************/
	//�浹�˻�//
	for (int layerI = 0; layerI < MAX_LAYER; layerI++)
	{
		for (int layerJ = 0; layerJ < MAX_LAYER; layerJ++)
		{
			if (layerI >= layerJ)
			{
				for (int i = 0; i < gameObject[layerI].size(); i++)
				{
					for (int j = 0; j < gameObject[layerJ].size(); j++)
					{

						//���� ���̾��....���ӿ�����Ʈ����...�浹�˻�//
						if (layerI == layerJ)
						{
							if (i > j)
							{
								GameObject* objI = gameObject[layerI][i];
								GameObject* objJ = gameObject[layerJ][j];

								checkObjectCollision(objI, objJ);
							}
						}
						else {

							//�ٸ� ���̰� ����...���ӿ�����Ʈ����...�浹�˻�//
							GameObject* objI = gameObject[layerI][i];
							GameObject* objJ = gameObject[layerJ][j];

							checkObjectCollision(objI, objJ);
						}
					}
				}

			}
		}
	}
	/**************************************************************/
}

void ObjectManager::checkObjectCollision(GameObject* objI, GameObject* objJ)
{
	if (objI->getDead() == false && objJ->getDead() == false && objI->getActive() == true && objJ->getActive()== true)
	{
		vector<BoxCollider2D*> boxI = objI->getBoxCollider2D();
		vector<BoxCollider2D*> boxJ = objJ->getBoxCollider2D();

		for (int ii = 0; ii < boxI.size(); ii++)
		{
			for (int jj = 0; jj < boxJ.size(); jj++)
			{
				//�ڽ���ǥ ���ϱ�
				float x0I, y0I, x1I, y1I; //boxI �浹ü�� �簢�� ������ ��ǥ
				float x0J, y0J, x1J, y1J; //boxJ �浹ü�� �簢�� ������ ��ǥ

				boxI[ii]->getBoxVertex(x0I, y0I, x1I, y1I);
				boxJ[jj]->getBoxVertex(x0J, y0J, x1J, y1J);

				if (!(x1J < x0I || x1I < x0J || y1I < y0J || y1J < y0I)) //if (x1J >= x0I && x1I >= x0J && y1I >= y0J && y1J >= y0I)					
				{
					//�浹 �̺�Ʈ..�˷��ֱ�//
					objI->onTriggerStay(objJ);  //objI����..objJ�ϰ� �浹������ �˸�
					objJ->onTriggerStay(objI);  //objJ����..objI�ϰ� �浹������ �˸�

					//�ϴ�...�浹�� �ѹ�...�߻��ϸ�...�ߺ��� �浹ó����..�����ϱ� ���ؼ�..�浹ó���� �ߴ���
					return;
				}
			}
		}
	}
}

void ObjectManager::draw()
{
	for (int layer = 0; layer < MAX_LAYER ; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			if (gameObject[layer][i]->getActive() == true)
			{
				gameObject[layer][i]->draw();
				gameObject[layer][i]->onDrawGizmos();
			}
		}
	}
}

void ObjectManager::clear()
{
	for (int layer = 0; layer < MAX_LAYER ; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			delete gameObject[layer][i];
		}

		gameObject[layer].clear();
	}
}

GameObject* ObjectManager::find(string name)
{
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			GameObject* o = gameObject[layer][i];

			if (o->getName() == name)
			{
				return o;
			}
		}
	}

	return nullptr;
}