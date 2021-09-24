#include "framework.h"

vector<GameObject*> ObjectManager::gameObject[MAX_LAYER];

void ObjectManager::instantiate(GameObject* o, int layer)
{
	gameObject[layer].push_back(o);
	o->start();
}

void ObjectManager::destroy(GameObject* o)
{
	//충돌검사쌍의 사용이 끝난후..삭제할 수 있도록...삭제...정보 표시를함//
	o->setDead(true);
}

void ObjectManager::update()
{
	//객체들 업데이트(이동, 발사)//
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
	//충돌 검사 이후에...삭제 표시 오브젝트를 제거하기//
	for (int layer = 0; layer < MAX_LAYER; layer++)
	{
		for (int i = 0; i < gameObject[layer].size(); i++)
		{
			if (gameObject[layer][i]->getDead() == true)
			{
				delete gameObject[layer][i];							//객체 삭제
				gameObject[layer].erase(gameObject[layer].begin() + i); //stl vector의 주소 저장 공간 삭제
				
				i--;  //삭제 대상인덱스를 건너뀌는것을 방지하기 위해서..인덱스를 감소시킴
			}
		}
	}
}

void ObjectManager::checkCollision()
{
	/***************************************************************/
	//충돌검사//
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

						//같은 레이어내의....게임오브젝트들의...충돌검사//
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

							//다른 레이거 같의...게임오브젝트들의...충돌검사//
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
				//박스좌표 구하기
				float x0I, y0I, x1I, y1I; //boxI 충돌체의 사각형 꼭지점 좌표
				float x0J, y0J, x1J, y1J; //boxJ 충돌체의 사각형 꼭지점 좌표

				boxI[ii]->getBoxVertex(x0I, y0I, x1I, y1I);
				boxJ[jj]->getBoxVertex(x0J, y0J, x1J, y1J);

				if (!(x1J < x0I || x1I < x0J || y1I < y0J || y1J < y0I)) //if (x1J >= x0I && x1I >= x0J && y1I >= y0J && y1J >= y0I)					
				{
					//충돌 이벤트..알려주기//
					objI->onTriggerStay(objJ);  //objI에게..objJ하고 충돌중임을 알림
					objJ->onTriggerStay(objI);  //objJ에게..objI하고 충돌줌임을 알림

					//일단...충돌이 한번...발생하면...중복된 충돌처리를..방지하기 위해서..충돌처리를 중단함
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