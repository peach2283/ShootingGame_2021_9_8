#include "framework.h"

Text::Text(float px, float py) : GameObject("","", true, px, py)
{
    library = nullptr;
    face    = nullptr;
}

Text::~Text()
{
    //��Ʈ��� ����
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

void Text::start()
{
    //��Ʈ ���̺귯�� �ʱ�ȭ
    if (FT_Init_FreeType(&library) == 0)
    {
        cout << "��Ʈ �ʱ�ȭ ����" << endl;
    }
    else {

        cout << "��Ʈ �ʱ�ȭ ����" << endl;
    }

    //��Ʈ..���� �ε��ϱ�//
    if (FT_New_Face(library, "Asset/Font/Medium.ttf", 0, &face) == 0)
    {
        cout << "��Ʈ ���� �ε� ����" << endl;
    }
    else {
        cout << "��Ʈ ���� �ε� ����" << endl;
    }

    //��Ʈ..ũ�� �����ϱ�//
    FT_Set_Pixel_Sizes(face, 64, 64);
}

void Text::draw()
{
    //���� �����ġ ����
    float fontx = getPx();
    float fonty = getPy();

    //���� ��Ʈ�� face���� ã�ƿ���
    wstring text = L"����";

    for (int i = 0; i < text.length(); i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);

        //font ������..��°����� �̹��� ���·�..��ȯ�ϱ�
        FT_Load_Glyph  (face, index, FT_LOAD_DEFAULT);       //��������(��ü - Glyph)�ε��ϱ�
        FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL); //���������� �̹����� ��ȯ�ϱ� 

        int width  = face->glyph->bitmap.width; //�̹��� ����ũ��
        int height = face->glyph->bitmap.rows;  //�̹��� ����ũ��
        unsigned char* buffer = face->glyph->bitmap.buffer; //�̹��� ����Ÿ ����

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char value = buffer[y * width + x];

                if (value > 0)  //��Ʈ �̹��� ����ϱ�
                {
                    //���ĺ���//
                    float alpha = value / 255.0f;  //���İ��� ( 0 ~ 1.0 ���̷�..����ȭ)

                    //���� ��������//
                    unsigned char R, G, B;
                    getPixel(fontx + x, fonty + y, &R, &G, &B);

                    //��Ʈ ����//
                    unsigned char r=255, g=0, b=0;

                    //���ĺ��� ���������ϱ�
                    unsigned char _r = r * alpha + R * (1 - alpha);
                    unsigned char _g = g * alpha + G * (1 - alpha);
                    unsigned char _b = b * alpha + B * (1 - alpha);

                    setPixel(fontx+x, fonty+y, _r, _g, _b);
                }
            }            
        }

        //���� ������� ��ġ��..�̵��ϱ�//
        fontx = fontx + face->glyph->advance.x/64;
        fonty = fonty + face->glyph->advance.y/64;
    }
}