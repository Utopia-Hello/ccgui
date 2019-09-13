#include "button.h"
#include "button_p.h"

#include "../events/PaintEvent.h"
#include "../tools/painter.h"


static const Rect s_button_init_rect = { 0, 0, 80, 30 };
static const Color  s_bg_color_default = COLOR_WHITE;

static void _OnPaint(Widget w, PaintEvent e)
{
    _Button* button = (_Button*)w;
    Painter painter = PainterCreate(w);
    int i, j;

    PainterSetColor(painter, button->bg_color);

    for (i = 0; i < WidgetGetWidth(w); i++)
    {
        for (j = 0; j < WidgetGetHeight(w); j++)
        {
            PainterDrawPoint(painter, i, j);
        }
    }

    PainterDelete(painter);
}

static void _OnMousePress(Widget w, MouseEvent e)
{
    ButtonSetBackgroundColor((Button)w, COLOR_BLUE);
    WidgetUpdate(w);
}

static void _Event(Widget w, Event e)
{
    switch (EventGetType(e))
    {
    case EVENT_TYPE_PAINT:
        _OnPaint(w, e);
        break;
    case EVENT_TYPE_MOUSE_PRESS:
        _OnMousePress(w, e);
        break;
    default:
        break;
    }
}


Button ButtonCreate(Widget parent)
{
    _Button* lp_button = malloc(sizeof(_Button));
    if (!lp_button)
    {
        return (Button)NULL;
    }

    // parent class init
    _WidgetInit((_Widget*)lp_button, (_Widget*)parent, &s_button_init_rect);

    // this init
    ButtonSetBackgroundColor((Widget)lp_button, s_bg_color_default);
    WidgetSetEventF((Widget)lp_button, _Event);
    WidgetShow(lp_button);

    return (Button)lp_button;
}

void ButtonDelete(Button b)
{
    if (b)
    {
        free(b);
    }
}

void ButtonSetBackgroundColor(Button b, Color color)
{
    _Button* lp_button = (_Button*)b;
    if (!lp_button)
    {
        return;
    }

    lp_button->bg_color = color;
}
