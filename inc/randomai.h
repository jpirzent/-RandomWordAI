#ifndef RANDOMAI_H
#define RANDOMAI_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void ft_freetab(char ***tab);

char *createRandomString(int len);
char *crossover(char *mate1, char *mate2);
char *mutate(char *child, float mutRate);

char **generatePopulation(int len, int popSize);
char **createMatingPool(float *fit, char **population, int popSize);
char **newGeneration(char **matingPool, int mateSize, float mutRate, int popSize);

int genAsciiVal();
int ft_random(int min, int max);
int sizeMatingPool(float *fit, int popSize);
int calcBestFitness(float *fit, int popSize);
int evaluate(char *best, char *target);

float calculateFitness(char *element, char *target);
float calculateAverageFitness(float *fit, int popSize);

float *generateFitness(char **population, char *target, int popSize);

#endif
