#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "../tools/global.h"

typedef Handle Window;


Window  WindowCreate();
void    WindowShow(Window w);
void    WindowSetPos(Window w, int32_t x, int32_t y);
void    WindowSetSize(Window w, int32_t width, int32_t height);



#endif
