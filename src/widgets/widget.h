#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "../tools/global.h"
#include "../events/event.h"

typedef Handle Widget;

typedef void(*EventF)(Widget w, Event e);

Widget  WidgetCreate(Widget parent);
void    WidgetDelete(Widget w);

void    WidgetShow(Widget w);
void    WidgetUpdate(Widget w);
void    WidgetSetRegion(Widget w, int32_t x, int32_t y, int32_t width, int32_t height);
void    WidgetMove(Widget w, int32_t x, int32_t y);
void    WidgetSetSize(Widget w, int32_t width, int32_t height);


int32_t WidgetGetPosX(Widget w);
int32_t WidgetGetPosY(Widget w);

int32_t WidgetGetWidth(Widget w);
int32_t WidgetGetHeight(Widget w);

Handle  WidgetGetId(Widget w);
Widget  WidgetGetParent(Widget w);
void    WidgetSetEventF(Widget w, EventF f);

#endif //__WIDGET_H__
