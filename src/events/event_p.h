#ifndef __EVENT_P_H__
#define __EVENT_P_H__

#include "../tools/global.h"
#include "event.h"

typedef struct _Event _Event;

struct _Event
{
    EventType  type;
};

void _EventSetType(_Event* e, EventType  type);

#endif
