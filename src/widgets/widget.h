#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "../global/global.h"

typedef Handle Widget;


Widget  WidgetCreate(Widget parent);
void    WidgetShow(Widget w);
void    WidgetSetPos(Widget w, int32_t x, int32_t y);
void    WidgetSetSize(Widget w, int32_t width, int32_t height);



#endif //__WIDGET_H__
