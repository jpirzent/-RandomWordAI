#include "../inc/randomai.h"

int evaluate(char *best, char *target)
{
    int ret;

    ret = strcmp(best, target);

    if (ret == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}