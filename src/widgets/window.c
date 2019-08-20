#include "window.h"
#include "window_p.h"


Window WindowCreate(Widget parent)
{
    _Window* lp_window = (_Window*)malloc(sizeof(_Window));

    if (!lp_window)
    {

        return NULL;
    }

    lp_window->widget = WidgetCreate(parent);

    return (Window)lp_window;
}

void WindowShow(Window w)
{
    _Window* lp_window = (_Window*)w;

    WidgetShow(lp_window->widget);
}

void WindowSetPos(Window w, int32_t x, int32_t y)
{
    _Window* lp_window = (_Window*)w;

    //WidgetSetPos(lp_window->widget, x, y);
}

void WindowSetSize(Window w, int32_t width, int32_t height)
{
    _Window* lp_window = (_Window*)w;

    //WidgetSetSize(lp_window->widget, width, height);
}
