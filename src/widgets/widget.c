#include "widget.h"
#include "widget_p.h"

#include <string.h>


#define _WIDGET_DEFAULT_X0      (0)
#define _WIDGET_DEFAULT_Y0      (0)

#define _WIDGET_DEFAULT_WIDTH   (400)
#define _WIDGET_DEFAULT_HEIGHT  (300)


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

void _WidgetOnPaint(Handle wid, Handle painter)
{
    _Widget* lp_widget = _find(wid);
    if (!lp_widget)
    {
        return;
    }

    for (int i = 0; i < 50; i += 5)
    {
        _WidgetSetPixel_platform(wid, painter, i, 20, 16777215);
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

    memset(lp_widget, 0, sizeof(_Widget));

    if (!parent)
    {
        lp_widget->rect.x0 = _WIDGET_DEFAULT_X0;
        lp_widget->rect.y0 = _WIDGET_DEFAULT_Y0;
        lp_widget->rect.x1 = _WIDGET_DEFAULT_X0 + _WIDGET_DEFAULT_WIDTH;
        lp_widget->rect.y1 = _WIDGET_DEFAULT_Y0 + _WIDGET_DEFAULT_HEIGHT;

        lp_widget->widget_id = _WidgetCreate_platform(); // desktop create
    }
    else
    {
        lp_widget->rect.x0 = 100;
        lp_widget->rect.y0 = 100;
        lp_widget->rect.x1 = 50;
        lp_widget->rect.y1 = 30;
    }

    _addChild((_Widget*)parent, lp_widget);

    _push(lp_widget);

    return (Widget*)lp_widget;
}

void WidgetShow(Widget w)
{
    _Widget* lp_widget = (_Widget*)w;

    _WidgetShow_platform(lp_widget->widget_id);
}
