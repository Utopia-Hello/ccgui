#include "../../widgets/widget_p.h"

#include <Windows.h>


static const char* s_class_name = "window";


extern int GetCmdShow(void);


static LRESULT CALLBACK _WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    switch (message) 
    {
    case WM_CREATE:
        break;
    case WM_TIMER:
        break;
    case WM_PAINT:
    {
        HDC         hDC;
        PAINTSTRUCT ps;
        hDC = BeginPaint(hWnd, &ps);
        _WidgetOnPaint((Handle)hWnd, (Handle)&ps);
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_RBUTTONDOWN:
        break;
    case WM_LBUTTONUP:
    case WM_LBUTTONDOWN:
    case WM_MOUSEMOVE:
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

static void _RegisterClass(void)
{
    WNDCLASSEX wcex;
    ATOM r;

    wcex.cbSize       = sizeof(WNDCLASSEX); 
    wcex.style			= CS_HREDRAW | CS_VREDRAW ;
    wcex.lpfnWndProc	= _WndProc;
    wcex.cbClsExtra		= 0;
    wcex.cbWndExtra		= 0;
    wcex.hInstance		= GetModuleHandle(NULL);
    wcex.hIcon			= NULL;
    wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
    //wcex.hbrBackground	= (HBRUSH)(COLOR_APPWORKSPACE+1);
    wcex.hbrBackground  = (HBRUSH)GetStockObject(GRAY_BRUSH);
    wcex.lpszMenuName	= NULL;
    wcex.lpszClassName	= s_class_name;
    wcex.hIconSm        = NULL;

    r = RegisterClassEx(&wcex);
}

Handle _WidgetCreate_platform()
{
    HWND l_wnd;

    _RegisterClass();
    
    l_wnd = CreateWindow(   s_class_name,
                            NULL,
                            WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_POPUP,
                            //WS_OVERLAPPEDWINDOW,
                            //CW_USEDEFAULT, 400, CW_USEDEFAULT, 300,
                            600, 400, 400, 300,
                            NULL, NULL, GetModuleHandle(NULL), NULL);
/*
    l_wnd = CreateWindowEx( WS_EX_APPWINDOW, 
                            s_class_name,
                            NULL,
                            WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP, 
                            //WS_POPUP,
                            600, 400, 400, 300, 
                            NULL, NULL, GetModuleHandle(NULL), NULL); */

    UpdateWindow(l_wnd);

    return (Handle)l_wnd;
}

void _WidgetShow_platform(Handle wid)
{
    HWND l_wnd = (HWND)wid;

    ShowWindow(l_wnd, SW_SHOW);
}

void _WidgetSetPixel_platform(Handle wid, Handle painter, uint32_t x, uint32_t y, uint32_t color)
{
    PAINTSTRUCT* ps = painter;
    //SetPixel(ps->hdc, x, y, RGB(0, 0, 0)); //»æÖÆÏñËØµã
    SetPixel(ps->hdc, x, y, color);
}
