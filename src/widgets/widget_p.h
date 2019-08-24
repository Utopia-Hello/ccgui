#ifndef __WIDGET_P_H__
#define __WIDGET_P_H__

#include "../tools/global.h"
#include "../tools/rect.h"
#include "../events/PaintEvent.h"

typedef struct _Widget _Widget;

struct _Widget
{
    Rect            rect;
    Handle          widget_id;
    Handle          paint_obj;
    PaintEventF     paint_event_f;


    _Widget*    parent;
    _Widget*    first_child;
    _Widget*    prev_sibling;
    _Widget*    next_sibling;
};


Handle  _WidgetCreate_platform(_Widget* w);
void    _WidgetShow_platform(_Widget* w);
void    _WidgetSetRegion_platform(_Widget* w);
void    _WidgetSetPixel_platform(Handle paint_obj, int32_t x, int32_t y, Color color);


int     _WidgetInit(_Widget* w, _Widget* parent, const Rect* r);
void    _WidgetOnPaint(Handle wid, Handle paint_obj);


#endif
