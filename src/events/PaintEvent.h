#ifndef __PAINT_EVENT_H__
#define __PAINT_EVENT_H__

#include "../tools/global.h"
//#include "../widgets/widget.h"

typedef Handle PaintEvent;
typedef Handle Widget;

typedef void(*PaintEventF)(Widget w, PaintEvent e);


#endif //__PAINT_EVENT_H__
