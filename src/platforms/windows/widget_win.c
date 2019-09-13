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
        break;
    case WM_LBUTTONDOWN:
    {
        _WidgetOnMousePress((Handle)hWnd, MOUSE_BUTTON_LEFT);
        break;
    }
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
    wcex.hbrBackground  = (HBRUSH)GetStockObject(GRAY_BRUSH);
    //wcex.hbrBackground  = NULL;
    wcex.lpszMenuName	= NULL;
    wcex.lpszClassName	= s_class_name;
    wcex.hIconSm        = NULL;

    r = RegisterClassEx(&wcex);
}

Handle _WidgetCreate_platform(_Widget* w)
{
    HWND l_wnd;
    HWND l_wnd_parent = NULL;
    DWORD l_dwStyle = WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_POPUP;
    DWORD l_dwExStyle = WS_EX_LEFT; //WS_EX_LAYERED;

    _RegisterClass();

    if (w->parent)
    {
        l_wnd_parent = (HWND)w->parent->widget_id;
        l_dwStyle = WS_CHILD | WS_VISIBLE;
        l_dwExStyle = WS_EX_LEFT;
    }
    
    /*
    l_wnd = CreateWindow(   s_class_name,
                            NULL,
                            WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_POPUP,
                            //WS_OVERLAPPEDWINDOW,
                            //CW_USEDEFAULT, 400, CW_USEDEFAULT, 300,
                            600, 400, 400, 300,
                            NULL, NULL, GetModuleHandle(NULL), NULL); */

    l_wnd = CreateWindowEx( l_dwExStyle,
                            s_class_name,
                            NULL,
                            l_dwStyle,
                            w->rect.x0, w->rect.y0, w->rect.x1 - w->rect.x0, w->rect.y1 - w->rect.y0,
                            l_wnd_parent, NULL, GetModuleHandle(NULL), NULL);

    if (!w->parent)
    {
        //SetLayeredWindowAttributes(l_wnd, 0, 120, LWA_ALPHA);
    }
    
    //UpdateWindow(l_wnd);

    return (Handle)l_wnd;
}

void _WidgetShow_platform(_Widget* w)
{
    HWND l_wnd = (HWND)w->widget_id;
    ShowWindow(l_wnd, SW_SHOW);
}

void _WidgetUpdate_platform(_Widget* w)
{
    HWND l_wnd = (HWND)w->widget_id;
    InvalidateRect(l_wnd, NULL, FALSE);
    UpdateWindow(l_wnd);
}

void _WidgetSetRegion_platform(_Widget* w)
{
    HWND l_wnd = (HWND)w->widget_id;
    MoveWindow(l_wnd, 
                w->rect.x0, 
                w->rect.y0, 
                w->rect.x1 - w->rect.x0, 
                w->rect.y1 - w->rect.y0, 
                FALSE);
}

// not support alpha
#define _COLOR_CONVERT(color)  (COLORREF)( color & 0x0000ff00 | (color & 0x00ff0000)>>16 | (color & 0x000000ff)<<16 )

void _WidgetSetPixel_platform(Handle paint_obj, int32_t x, int32_t y, Color color)
{
    PAINTSTRUCT* ps = paint_obj;
    SetPixel(ps->hdc, x, y, _COLOR_CONVERT(color)); //RGB()
}
