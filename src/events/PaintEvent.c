#include "paintevent.h"
#include "paintevent_p.h"

PaintEvent PaintEventCreate()
{
    _PaintEvent* lp_event = malloc(sizeof(_PaintEvent));
    if (!lp_event)
    {
        return (PaintEvent)NULL;
    }

    // this init
    _EventSetType((_Event*)lp_event, EVENT_TYPE_PAINT);

    return (PaintEvent)lp_event;
}

void PaintEventDelete(PaintEvent e)
{
    if (e)
    {
        free(e);
    }
}

