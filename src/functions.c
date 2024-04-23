#include "../inc/randomai.h"

//Generates random ascii value for Element
int genAsciiVal()
{
    int ret = ft_random(32, 122);

    return (ret);
}

int ft_random(int min, int max)
{
    int range = max - min;

    int ret = rand() % range;

    ret = ret + min;

    return (ret);
}

void ft_freetab(char ***tab)
{
    int i;

    i = 0;
    if (!tab || !*tab)
        return;
    while ((*tab)[i] != NULL)
    {
        free((*tab)[i]);
        i++;
    }
    free((*tab));
}

void conlog(char *str)
{
    printf("%s", str);
}