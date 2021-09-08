#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

#include "BMP.h"
#include "graphic.h"

void Bitmap::readBMP(const char* fileName, Image* img)
{
	//��Ʈ����������� ��Ʈ���������..����ü//
	BITMAPFILEHEADER  fileHeader;
	BITMAPINFOHEADER  infoHeader;

	//��Ʈ�� ���� �б�
	FILE* stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//��Ʈ������ ���..����ü �о����
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		//----��Ʈ�� ���� ���...����ü...����ϱ�-----//
		//printf("-------��Ʈ�� ���� ��� ����ü------\n");

		//printf("bfType 0X%X\n", fileHeader.bfType); //���Ͼȿ���..bmp���� Ȯ�� �ڵ�(�����ڵ�)
		//printf("bfSize %d\n", fileHeader.bfSize); //���� ũ��
		//printf("bfReserved1 %d\n", fileHeader.bfReserved1); //���߻�� ������
		//printf("bfReserved2 %d\n", fileHeader.bfReserved2); //���߻�� ������
		//printf("bfOffBits   %d\n", fileHeader.bfOffBits);   //��Ʈ�ʵ���Ÿ(�ȼ�����Ÿ)�� ������ġ(����)

		//��Ʈ������ ���..����ü �о����//
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		//---��Ʈ�� ���� ���..����ü...����ϰ�---//
		//printf("------��Ʈ�� ���� ���..����ü ------\n");
		//printf("�̹��� ũ�� (%d x %d)\n", infoHeader.biWidth, infoHeader.biHeight);
		//printf("��Ʈ ����  %d\n", infoHeader.biBitCount);
		//printf("�̹��� �ε� �迭 ũ�� %d\n", infoHeader.biSizeImage);

		//�ȼ�����Ÿ �迭 �о����//
		int length = infoHeader.biSizeImage / 4;

		img->width = infoHeader.biWidth;
		img->height = infoHeader.biHeight;
		img->argb = new uint[length];            //unsigned int �� 4����Ʈ ����

		fread(img->argb, sizeof(uint), length, stream);

		//���� �ݱ�
		fclose(stream);

	}
	else {
		printf("��Ʈ�� ������ ���� �����ϴ�\n");
	}
}

void Bitmap::readBMP(const char* fileName, int x, int y, int width, int height, Image* img)
{
	//��Ʈ����������� ��Ʈ���������..����ü//
	BITMAPFILEHEADER  fileHeader;
	BITMAPINFOHEADER  infoHeader;

	//��Ʈ�� ���� �б�
	FILE* stream = fopen(fileName, "rb");

	if (stream != nullptr)
	{
		//��Ʈ������ ���..����ü �о����
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		//��Ʈ������ ���..����ü �о����//
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		//�ȼ�����Ÿ �迭 �о����//
		int length = width * height;

		img->width  = width;  
		img->height = height;
		img->argb   = new uint[length];            //unsigned int �� 4����Ʈ ����

		//�̹��� ��������...fseek �ϱ�//
		int offset = (y * infoHeader.biWidth + x) * 4 ;
		fseek(stream, offset, SEEK_CUR);

		//�¿� ����� ...fseek �ϱ�//
		int gap = (infoHeader.biWidth - width)*4;

		for (int i = 0; i < height; i++)
		{
			fread(img->argb + i*width, sizeof(uint), width, stream);
			fseek(stream, gap, SEEK_CUR);
		}

		//���� �ݱ�
		fclose(stream);

	}
	else {
		printf("��Ʈ�� ������ ���� �����ϴ�\n");
	}

}

void Bitmap::drawBMP(float px, float py, Image* img)
{
	//�̹��� ����ϱ�//
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			uint pixel = img->argb[y * img->width + x];

			setPixel(px + x, py + y, pixel);
		}
	}
}
