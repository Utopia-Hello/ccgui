#ifndef __MOUSE_EVENT_P_H__
#define __MOUSE_EVENT_P_H__

#include "../tools/global.h"
#include "event_p.h"
#include "mouseevent.h"

typedef struct _MouseEvent _MouseEvent;

struct _MouseEvent
{
    _Event      e;
    MouseButton b;
};

#endif //__MOUSE_EVENT_P_H__
