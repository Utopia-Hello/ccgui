#ifndef __PAINT_EVENT_H__
#define __PAINT_EVENT_H__

#include "../tools/global.h"

typedef Handle PaintEvent;

PaintEvent  PaintEventCreate();
void        PaintEventDelete(PaintEvent e);

#endif //__PAINT_EVENT_H__
