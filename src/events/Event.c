#include "event.h"
#include "event_p.h"

EventType EventGetType(Event e)
{
    _Event* lp_event = (_Event*)e;
    if (!e)
    {
        return EVENT_TYPE_BASE;
    }

    return lp_event->type;
}

void _EventSetType(_Event* e, EventType  type)
{
    if (e)
    {
        e->type = type;
    }
}
