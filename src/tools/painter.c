#include "painter.h"
#include "painter_p.h"


int _PainterInit(_Painter* painter, _Widget* w)
{
    memset(painter, 0, sizeof(_Painter));
    painter->paint_obj = w->paint_obj;

    return 1;
}

Painter PainterCreate(Widget w)
{
    _Painter* lp_painter = malloc(sizeof(_Painter));
    if (!lp_painter)
    {
        return (Painter)NULL;
    }

    _PainterInit(lp_painter, (_Widget*)w);

    return (Painter)lp_painter;
}

void PainterDrawPoint(Painter p, int32_t x, int32_t y)
{
    _Painter* lp_painter = (_Painter*)p;

    _WidgetSetPixel_platform(lp_painter->paint_obj, x, y, 0x00aabbcc);
}
