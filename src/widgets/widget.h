#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "../tools/global.h"
#include "../events/PaintEvent.h"

typedef Handle Widget;


Widget  WidgetCreate(Widget parent);
void    WidgetShow(Widget w);
void    WidgetSetRegion(Widget w, int32_t x, int32_t y, int32_t width, int32_t height);
void    WidgetMove(Widget w, int32_t x, int32_t y);
void    WidgetSetSize(Widget w, int32_t width, int32_t height);


int32_t WidgetGetPosX(Widget w);
int32_t WidgetGetPosY(Widget w);

int32_t WidgetGetWidth(Widget w);
int32_t WidgetGetHeight(Widget w);

Handle  WidgetGetId(Widget w);
Widget  WidgetGetParent(Widget w);
void    WidgetSetPaintEvent(Widget w, PaintEventF f);

#endif //__WIDGET_H__
