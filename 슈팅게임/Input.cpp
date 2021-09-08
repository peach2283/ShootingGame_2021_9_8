#include "framework.h"

Input::State  Input::state[9] = { State::keyUpRep, State::keyUpRep,State::keyUpRep,State::keyUpRep, State::keyUpRep,State::keyUpRep,State::keyUpRep, State::keyUpRep, State::keyUpRep };  //0-���� ����, 1-�ѹ� ���� 2-������ ����, 3-�ѹ�����
int			  Input::key[9]   = { VK_LBUTTON     , VK_RBUTTON     , VK_MBUTTON    ,  VK_LEFT      , VK_RIGHT       , VK_UP         , VK_DOWN        , VK_SPACE       , 'Z' };
string		  Input::name[9]  = { "lbutton"      , "rbuttom"      , "mbutton",       "left",           "right",       "up"         ,  "down"        , "space",         "z" };

void Input::update()
{
	//Ű�迭��...���¾�����Ʈ
	for (int i = 0; i < 9; i++)
	{
		if (state[i] == State::keyUpRep)       //State::keyUpRep-���� ����
		{
			if (GetAsyncKeyState(key[i]) != 0) //����
			{
				state[i] = State::keyDown;  // �ѹ� ���� ���·�..����
			}
			else //����
			{
				//state = 0;
			}
		}
		else if (state[i] == State::keyDown) //�ѹ� ���� 
		{
			//cout << "Ű�� �ѹ� ����" << endl;

			if (GetAsyncKeyState(key[i]) != 0) //����
			{
				state[i] = State::keyDownRep;  //������ ���� ���·�..����
			}
			else //����
			{
				state[i] = State::keyUp;//�ѹ����� ���·�..����
			}
		}
		else if (state[i] == State::keyDownRep) //������ ����
		{
			//cout << ".";

			if (GetAsyncKeyState(key[i]) == 0) //����
			{
				state[i] = State::keyUp;  //�ѹ����� ���·�..����
			}
			else //����
			{
				//state = 2;
			}

		}
		else if (state[i] == State::keyUp) //3-�ѹ�����
		{
			//cout << "Ű�� �ѹ� ����" << endl;

			if (GetAsyncKeyState(key[i]) == 0) //Ű�� ����
			{
				state[i] = State::keyUpRep;  //���� ���� ���·�..����
			}
			else //Ű ����
			{
				state[i] = State::keyUpRep; // �ѹ� ���� ���·�..����
			}
		}
	}
}

bool Input::getKeyDown(string keyName)
{
	//Ű�̸� ... �ε��� ã��//
	for (int i = 0; i < 9; i++)
	{
		if (name[i] == keyName)
		{
			if (state[i] == State::keyDown)
			{
				return true;
			}
			else {
				return false;
			}
		}
	}
	
	return false; //�̸� �迭��..Ű �̸��� ���� ��� (������ �ȴ���)
}

bool Input::getKeyUp(string keyName)
{
	//Ű�̸� ... �ε��� ã��//
	for (int i = 0; i < 9; i++)
	{
		if (name[i] == keyName)
		{
			if (state[i] == State::keyUp)
			{
				return true;
			}
			else {
				return false;
			}
		}
	}

	return false; //�̸� �迭��..Ű �̸��� ���� ��� (������ �ȴ���)
}

bool Input::getKey(string keyName)
{
	//Ű�̸� ... �ε��� ã��//
	for (int i = 0; i < 9; i++)
	{
		if (name[i] == keyName)
		{
			if (state[i] == State::keyDownRep || state[i] == State::keyDown)
			{
				return true;
			}
			else {
				return false;
			}
		}
	}

	return false; //�̸� �迭��..Ű �̸��� ���� ��� (������ �ȴ���)
}