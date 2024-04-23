#include "../inc/randomai.h"

char **generatePopulation(int len, int popSize)
{
    //initialize 2D array
    char **pop;
    int index = 0;

    pop = (char **)malloc(sizeof(char *) * popSize);

    //fill array
    while (index < popSize)
    {
        pop[index] = (char *)malloc(sizeof(char) * len);
        strcpy(pop[index], createRandomString(len));
        index++;
    }

    //return array
    return pop;
}

//Create Random Element for "Population"
char *createRandomString(int len)
{
    char *randChar;
    int index = 0;

    randChar = (char *)malloc(sizeof(char) * len);

    while (index < len)
    {
        randChar[index] = genAsciiVal();
        index++;
    }
    return (randChar);
}
