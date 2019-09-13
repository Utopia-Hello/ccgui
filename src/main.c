#include <stdio.h>

#include "./core/application.h"

#include "./widgets/widget.h"
#include "./widgets/window.h"
#include "./widgets/button.h"

#include "./tools/painter.h"


static void _OnPaint(Widget w, PaintEvent e)
{
    Painter painter = PainterCreate(w);
    int i, j;

    PainterSetColor(painter, COLOR_WHITE);

    for (i = 0; i < 200; i += 1)
    {
        for (j = 10; j < 50; j++)
        {
            PainterDrawPoint(painter, i, j);
        }
    }

    PainterDelete(painter);
}

static void _OnMousePress(Widget w, MouseEvent e)
{
    Painter painter = PainterCreate(w);
    int i, j;

    PainterSetColor(painter, COLOR_RED);

    for (i = 0; i < 200; i += 1)
    {
        for (j = 10; j < 50; j++)
        {
            PainterDrawPoint(painter, i, j);
        }
    }

    PainterDelete(painter);
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
    case EVENT_TYPE_MOUSE_RELEASE:
        //_OnMouseRelease(w, e);
        break;
    case EVENT_TYPE_MOUSE_MOVE:
        //_OnMouseMove(w, e);
        break;
    default:
        break;
    }
}

int main(int argc, char* argv[])
{
    Widget w = NULL;
    Button b = NULL;

    ApplicationInit();

    w = WidgetCreate(NULL);
    b = ButtonCreate(w);

    //WidgetSetEventF(w, _Event);

    WidgetMove(w, 500, 500);
    WidgetMove(b, 5, 5);
    WidgetSetSize(b, 200, 80);

    WidgetShow(w);

    return ApplicationRun();
}