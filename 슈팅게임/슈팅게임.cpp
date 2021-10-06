// 슈팅게임.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "슈팅게임.h"

#define MAX_LOADSTRING 100


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND      hWnd;                                 // 현재 윈도우핸들 입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
  
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg = {0,0,0, 0,0,0};

    //초기화 
    START_DEBUG_CONSOLE();                   //디버그 콘솔창 열기
    initGraphic(hWnd, 0, 0, WIDTH, HEIGHT);  //그래픽 초기화

    Random::Init();         //랜덤 초기화
    Time::init();           //타이머 초기화
    SceneManager::init();   //씬매니저 초기화

    // 기본 메시지 루프입니다:
    while (msg.message != WM_QUIT && Application::getIsPlaying() == true)
    {   
        //윈도우..동작..//
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) == TRUE)
        {           
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

         //게임..동작..//
         clear(0, 0, 0);

         Time::update();        //델타타임 업데이트
         Input::update();       //키상태   업데이트
         SceneManager::run();   //씬구동하기

         render();
    }
  
    //종료
    SceneManager::unload();
    STOP_DEBUG_CONSOLE();
    exitGraphic();

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우 크기 조정하기
   RECT rt = { 0,0,WIDTH, HEIGHT };

   AdjustWindowRect(&rt, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE);

   int width  = rt.right  - rt.left;
   int height = rt.bottom - rt.top;

   hWnd = CreateWindowW(szWindowClass, 
                             szTitle, 
                             WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
                             CW_USEDEFAULT, 
                             0, 
                             width,   //윈도우 가로크기
                             height,  //윈도우 세로크기
                             nullptr, 
                             nullptr, 
                             hInstance, 
                             nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {   
    //마우스 좌표//
    case WM_LBUTTONUP:
    case WM_LBUTTONDOWN:

    case WM_RBUTTONUP:
    case WM_RBUTTONDOWN:

    case WM_MBUTTONUP:
    case WM_MBUTTONDOWN:

    case WM_MOUSEMOVE:
        {
            short mx = LOWORD(lParam);  //하위 2바이트
            short my = HIWORD(lParam);  //상위 2바이트
            
            Input::mousePosition.x = (float) mx;
            Input::mousePosition.y = (float) my;            
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            render();

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}