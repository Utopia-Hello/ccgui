#include <stdio.h>

#include "./widgets/widget.h"
#include "./widgets/window.h"
#include "./widgets/button.h"
#include "./core/application.h"


int main()
{
    Widget w;
    Button b;
    //Window w1;

    ApplicationInit();

    w = WidgetCreate(NULL);
    b = ButtonCreate(w);
    //w1 = WindowCreate();

    WidgetShow(w);
    //WindowShow(w1);

    return ApplicationRun();
}