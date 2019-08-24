#ifndef __PAINTER_H__
#define __PAINTER_H__

#include "../tools/global.h"
#include "../widgets/widget.h"

typedef Handle Painter;

Painter PainterCreate(Widget w);

void PainterDrawPoint(Painter p, int32_t x, int32_t y);


#endif
