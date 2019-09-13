#include "widget.h"
#include "widget_p.h"

#include "../events/event_p.h"


static const Rect s_widget_init_rect = { 200, 200, 600, 500 };


#define _WIDGET_NUM_MAX         (1000)

_Widget* s_vectWidgets[_WIDGET_NUM_MAX] = { 0 };



static int _push(_Widget* pWidget)
{
    int i;

    for (i = 0; i < _WIDGET_NUM_MAX; i++)
    {
        if (s_vectWidgets[i] == NULL)
        {
            s_vectWidgets[i] = pWidget;
            return 1;
        }
    }

    return 0;
}

static int _pop(_Widget* pWidget)
{
    int i;

    for (i = 0; i < _WIDGET_NUM_MAX; i++)
    {
        if (s_vectWidgets[i] == pWidget)
        {
            s_vectWidgets[i] = NULL;
            return 1;
        }
    }

    return 0;
}

static _Widget* _find(Handle wid)
{
    int i;

    for (i = 0; i < _WIDGET_NUM_MAX; i++)
    {
        if (s_vectWidgets[i] && s_vectWidgets[i]->widget_id == wid)
        {
            return s_vectWidgets[i];
        }
    }

    return (_Widget*)NULL;
}

static int _addChild(_Widget* parent, _Widget* child)
{
    if (!parent)
    {
        return 1;
    }

    child->parent = parent;

    if (!parent->first_child)
    {
        parent->first_child = child;
    }
    else
    {
        _Widget* lp_child_itor;
        lp_child_itor = parent->first_child;
        while (lp_child_itor->next_sibling) // find terminal sibling
        {
            lp_child_itor = lp_child_itor->next_sibling;
        }
        lp_child_itor->next_sibling = child;
        child->prev_sibling = lp_child_itor;
    }

    return 0;
}

int _WidgetInit(_Widget* w, _Widget* parent, const Rect* r)
{
    memset(w, 0, sizeof(_Widget));

    w->rect = *r;
    w->parent = parent;

    w->widget_id = _WidgetCreate_platform(w);

    _addChild((_Widget*)parent, w);

    _push(w);

    return 1;
}

void _WidgetOnPaint(Handle wid, Handle paint_obj)
{
    _Widget* lp_widget = _find(wid);
    if (!lp_widget)
    {
        return;
    }

    lp_widget->paint_obj = paint_obj;

    if (lp_widget->event_f)
    {
        PaintEvent e = PaintEventCreate();
        _EventSetType(e, EVENT_TYPE_PAINT);
        lp_widget->event_f(lp_widget, e);
        PaintEventDelete(e);
    }
}

void _WidgetOnMousePress(Handle wid, MouseButton b)
{
    _Widget* lp_widget = _find(wid);
    if (!lp_widget)
    {
        return;
    }

    if (lp_widget->event_f)
    {
        MouseEvent e = MouseEventCreate();
        _EventSetType(e, EVENT_TYPE_MOUSE_PRESS);
        lp_widget->event_f(lp_widget, e);
        MouseEventDelete(e);
    }
}

Widget WidgetCreate(Widget parent)
{
    _Widget* lp_widget = malloc(sizeof(_Widget));

    if (!lp_widget)
    {
        // assert
        return (Widget*)NULL;
    }

    _WidgetInit(lp_widget, (_Widget*)parent, &s_widget_init_rect);

    return (Widget*)lp_widget;
}

void WidgetDelete(Widget w)
{
    if (w)
    {
        free(w);
    }
}

void WidgetShow(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    _WidgetShow_platform(lp_widget);
}

void WidgetUpdate(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    _WidgetUpdate_platform(lp_widget);
}

void WidgetSetRegion(Widget w, int32_t x, int32_t y, int32_t width, int32_t height)
{
    _Widget* lp_widget = (_Widget*)w;
    lp_widget->rect.x0 = x;
    lp_widget->rect.y0 = y;
    lp_widget->rect.x1 = x + width;
    lp_widget->rect.y1 = y + height;
    _WidgetSetRegion_platform(lp_widget);
}

void WidgetMove(Widget w, int32_t x, int32_t y)
{
    _Widget* lp_widget = (_Widget*)w;
    lp_widget->rect.x1 = x + lp_widget->rect.x1 - lp_widget->rect.x0;
    lp_widget->rect.y1 = y + lp_widget->rect.y1 - lp_widget->rect.y0;
    lp_widget->rect.x0 = x;
    lp_widget->rect.y0 = y;
    _WidgetSetRegion_platform(lp_widget);
}

void WidgetSetSize(Widget w, int32_t width, int32_t height)
{
    _Widget* lp_widget = (_Widget*)w;
    lp_widget->rect.x1 = lp_widget->rect.x1 + width;
    lp_widget->rect.y1 = lp_widget->rect.y1 + height;
    _WidgetSetRegion_platform(lp_widget);
}


int32_t WidgetGetPosX(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    return lp_widget->rect.x0;
}

int32_t WidgetGetPosY(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    return lp_widget->rect.y0;
}

int32_t WidgetGetWidth(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    return lp_widget->rect.x1 - lp_widget->rect.x0;
}

int32_t WidgetGetHeight(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    return lp_widget->rect.y1 - lp_widget->rect.y0;
}

Handle WidgetGetId(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    return lp_widget->widget_id;
}

Widget WidgetGetParent(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;
    return (Widget)lp_widget->parent;
}

void WidgetSetEventF(Widget w, EventF f)
{
    _Widget* lp_widget = (_Widget*)w;
    lp_widget->event_f = f;
}
