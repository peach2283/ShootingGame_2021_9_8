#include "framework.h"

Text::Text(float px, float py) : GameObject("","", true, px, py)
{
    library = nullptr;
    face    = nullptr;
}

Text::~Text()
{
    //폰트사용 종료
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

void Text::start()
{
    //폰트 라이브러리 초기화
    if (FT_Init_FreeType(&library) == 0)
    {
        cout << "폰트 초기화 성공" << endl;
    }
    else {

        cout << "폰트 초기화 실패" << endl;
    }

    //폰트..파일 로드하기//
    if (FT_New_Face(library, "Asset/Font/Medium.ttf", 0, &face) == 0)
    {
        cout << "폰트 파일 로드 성공" << endl;
    }
    else {
        cout << "폰트 파일 로드 실패" << endl;
    }

    //폰트..크기 지정하기//
    FT_Set_Pixel_Sizes(face, 32, 32);
}

void Text::draw()
{
    //글자 폰트를 face에서 찾아오기
    wstring text = L"점수";

    for (int i = 0; i < text.length(); i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);

        //font 정보를..출력가능한 이미지 형태로..변환하기
        FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);        //글자정보(서체 - Glyph)로드하기
        FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL); //글자정보를 이미지로 변환하기 

        int width = face->glyph->bitmap.width; //이미지 가로크기
        int height = face->glyph->bitmap.rows;  //이미지 세로크기
        unsigned char* buffer = face->glyph->bitmap.buffer; //이미지 데이타 버퍼

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char value = buffer[y * width + x];

                if (value > 0)  //폰트 이미지 출력하기
                {
                    //폰트 색상//
                    unsigned char r=255, g=0, b=0;

                    setPixel(x, y, r, g, b);
                }
            }            
        }
    }
}