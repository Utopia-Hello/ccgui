#ifndef __MOUSE_EVENT_H__
#define __MOUSE_EVENT_H__

#include "../tools/global.h"

typedef Handle MouseEvent;

typedef enum
{
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_RIGHT,
}MouseButton;

MouseEvent  MouseEventCreate();
void        MouseEventDelete(MouseEvent e);

#endif
