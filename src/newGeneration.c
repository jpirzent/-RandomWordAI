#include "../inc/randomai.h"

char **newGeneration(char **matingPool, int mateSize, float mutRate, int popSize)
{
    int a, b;
    char *mate1;
    char *mate2;
    char **newGen;
    char *child;
    char *child_m;

    int index = 0;
    int len = strlen(matingPool[0]);

    newGen = (char **)malloc(sizeof(char *) * popSize);

    while (index < popSize)
    {
        newGen[index] = (char *)malloc(sizeof(char) * len);

        a = ft_random(0, mateSize);
        b = ft_random(0, mateSize);

        mate1 = (char *)malloc(sizeof(char) * len);
        mate2 = (char *)malloc(sizeof(char) * len);

        strcpy(mate1, matingPool[a]);
        strcpy(mate2, matingPool[b]);

        child = crossover(mate1, mate2);
        child_m = mutate(child, mutRate);

        strcpy(newGen[index], child_m);

        free(mate1);
        free(mate2);
        free(child);
        free(child_m);
        index++;
    }

    return (newGen);
}

char *crossover(char *mate1, char *mate2)
{
    int index = 0;
    int len = strlen(mate1);
    int midpoint = ft_random(0, len);
    char *child;

    child = (char *)malloc(sizeof(char) * len);

    while (index < len)
    {
        // if (index % 2 == 0)
        // {
        //     child[index] = mate1[index];
        // }
        // else
        // {
        //     child[index] = mate2[index];
        // }

        if (index < midpoint)
        {
            child[index] = mate1[index];
        }
        else
        {
            child[index] = mate2[index];
        }
        index++;
    }
    return child;
}

char *mutate(char *child, float mutRate)
{
    int len = strlen(child);
    int index = 0;
    int check = mutRate * 100;
    int ran;
    char *child_m;

    child_m = (char *)malloc(sizeof(char) * len);

    while (index < len)
    {
        ran = ft_random(0, 100);
        if (ran < check)
        {
            child_m[index] = ft_random(32, 123);
        }
        else
        {
            child_m[index] = child[index];
        }
        index++;
    }
    return (child_m);
}