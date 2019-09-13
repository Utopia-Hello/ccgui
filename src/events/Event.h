#ifndef __EVENT_H__
#define __EVENT_H__

#include "../tools/global.h"

#include "paintevent.h"
#include "mouseevent.h"

typedef Handle Event;

typedef enum
{
    EVENT_TYPE_BASE = 0,
    EVENT_TYPE_PAINT,
    EVENT_TYPE_MOUSE_PRESS,
    EVENT_TYPE_MOUSE_RELEASE,
    EVENT_TYPE_MOUSE_MOVE,
}EventType;

EventType   EventGetType(Event e);

#endif
