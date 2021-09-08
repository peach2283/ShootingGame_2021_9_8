#pragma once

class BoxCollider2D
{
private:
	float x, y;			 //�簢���� ������ ��ǥ
	float width, height; //�簢���� ����/����
public:
	BoxCollider2D(float x, float y, float width, float height);
	virtual ~BoxCollider2D();

	//�浹ü..��ǥ ��������//
	void getBox(float& x, float& y, float& width, float& height);
	void getBoxVertex(float& x0, float& y0, float& x1, float& y1);

	//�浹ü..�̵���Ű��//
	void translate(float x, float y);
};