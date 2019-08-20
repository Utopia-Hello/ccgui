#include "button.h"
#include "button_p.h"


static void _Event()
{

}


Button ButtonCreate(Widget parent)
{
    _Button* lp_button = malloc(sizeof(_Button));
    if (!lp_button)
    {
        return (Button)NULL;
    }

    lp_button->widget = WidgetCreate(parent);

    return (Button)lp_button;
}
