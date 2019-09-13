#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "../tools/global.h"
#include "widget.h"

typedef Widget Button;


Button  ButtonCreate(Widget parent);
void    ButtonDelete(Button b);

void    ButtonSetBackgroundColor(Button b, Color color);



#endif //__WIDGET_H__
