#ifndef __PAINTER_H__
#define __PAINTER_H__

#include "../tools/global.h"
#include "../widgets/widget.h"

typedef Handle Painter;

Painter PainterCreate(Widget w);
void    PainterDelete(Painter p);

void    PainterSetColor(Painter painter, Color color);


void PainterDrawPoint(Painter painter, int32_t x, int32_t y);


#endif
