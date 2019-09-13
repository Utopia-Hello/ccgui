#ifndef __PAINTER_P_H__
#define __PAINTER_P_H__

#include "../tools/global.h"
#include "../widgets/widget_p.h"

typedef struct _Painter _Painter;

struct _Painter
{
    Handle  paint_obj;
    Color   color;
};

int     _PainterInit(_Painter* painter, _Widget* w);


#endif
