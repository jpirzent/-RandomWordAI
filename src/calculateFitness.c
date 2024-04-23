#include "../inc/randomai.h"

float calculateFitness(char *element, char *target)
{
    int fitness = 0;
    int index = 0;
    int len = strlen(target);

    while (index < len)
    {
        if (element[index] == target[index])
        {
            fitness++;
        }
        index++;
    }

    float ret = (float)fitness / len;
    return (ret * 100);
}

float *generateFitness(char **population, char *target, int popSize)
{
    float *fit;
    int index = 0;

    fit = (float *)malloc(sizeof(float) * popSize);

    while (index < popSize)
    {
        fit[index] = calculateFitness(population[index], target);
        index++;
    }

    return fit;
}

float calculateAverageFitness(float *fit, int popSize)
{
    int index = 0;
    float average = 0;

    while (index < popSize)
    {
        average += fit[index];
        index++;
    }

    average = average / popSize;
    return average;
}

int calcBestFitness(float *fit, int popSize)
{
    int index = 0;
    int best = 0;

    while (index < popSize)
    {
        if (fit[index] > fit[best])
        {
            best = index;
        }
        index++;
    }
    return best;
}