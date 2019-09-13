#include "mouseevent.h"
#include "mouseevent_p.h"


MouseEvent  MouseEventCreate()
{
    _MouseEvent* lp_event = malloc(sizeof(_MouseEvent));
    if (!lp_event)
    {
        return (MouseEvent)NULL;
    }

    // this init
    _EventSetType((_Event*)lp_event, EVENT_TYPE_BASE);

    return (MouseEvent)lp_event;
}

void MouseEventDelete(MouseEvent e)
{
    if (e)
    {
        free(e);
    }
}

