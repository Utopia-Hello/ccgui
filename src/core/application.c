#include "application.h"


extern int _ApplicationRun(void);

int ApplicationInit(void)
{
    return 1;
}

int ApplicationRun(void)
{
    return _ApplicationRun();
}