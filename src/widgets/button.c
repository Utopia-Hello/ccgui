#include "button.h"
#include "button_p.h"

#include "../events/PaintEvent.h"
#include "../tools/painter.h"


static const Rect s_button_init_rect = { 0, 0, 80, 30 };


static void _PaintEvent(Widget w, PaintEvent e)
{
    Painter painter = PainterCreate(w);
    int i, j;

    for (i = 0; i < WidgetGetWidth(w); i++)
    {
        for (j = 0; j < WidgetGetHeight(w); j++)
        {
            PainterDrawPoint(painter, i, j);
        }
    }
}


Button ButtonCreate(Widget parent)
{
    _Button* lp_button = malloc(sizeof(_Button));
    if (!lp_button)
    {
        return (Button)NULL;
    }

    _WidgetInit((_Widget*)lp_button, (_Widget*)parent, &s_button_init_rect);

    WidgetSetPaintEvent((Widget)lp_button, _PaintEvent);

    return (Button)lp_button;
}
