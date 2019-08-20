#include <Windows.h>

int s_cmdShow = SW_SHOW;

extern int main(int, char**);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,  LPSTR lpCmdLine, int nCmdShow)
{
    s_cmdShow = nCmdShow;
    return main(0, NULL);
}

int GetCmdShow(void)
{
    return s_cmdShow;
}
