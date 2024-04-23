#include "../inc/randomai.h"

int sizeMatingPool(float *fit, int popSize)
{
    int totalSize = 0;
    int index = 0;

    while (index < popSize)
    {
        totalSize += round(fit[index]);
        index++;
    }

    return (totalSize);
}

char **createMatingPool(float *fit, char **population, int popSize)
{
    char **matingPool;
    int n;
    int index = 0;
    int j = 0;
    int len = strlen(population[0]);
    int mateSize = sizeMatingPool(fit, popSize);

    //malloc Pool
    matingPool = (char **)malloc(sizeof(char *) * mateSize);

    while (index < popSize)
    {
        n = round(fit[index]);
        while (n > 0)
        {
            matingPool[j] = (char *)malloc(sizeof(char) * len);
            strcpy(matingPool[j], population[index]);
            j++;
            n--;
        }
        index++;
    }

    return (matingPool);
}