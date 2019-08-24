#include <stdio.h>

#include "./core/application.h"

#include "./widgets/widget.h"
#include "./widgets/window.h"
#include "./widgets/button.h"

#include "./tools/painter.h"

static void _PaintEvent(Widget w, PaintEvent e)
{
    Painter painter = PainterCreate(w);
    int i;

    for (i = 0; i < 200; i += 1)
    {
        PainterDrawPoint(painter, i, 20);
    }
}

int main(int argc, char* argv[])
{
    Widget w = NULL;
    Button b = NULL;

    ApplicationInit();

    w = WidgetCreate(NULL);
    b = ButtonCreate(w);

    WidgetSetPaintEvent(w, _PaintEvent);

    WidgetMove(w, 500, 500);
    WidgetMove(b, 20, 50);

    WidgetShow(w);

    return ApplicationRun();
}