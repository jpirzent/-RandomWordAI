#include "../inc/randomai.h"

int main(int argc, char **argv)
{
    // system("clear");
    if (argc >= 2)
    {
        //Calculating Random Value
        srand(time(0));

        //Initializing Values
        int len = strlen(argv[1]);
        int popSize = 500;
        float mutRate = 0.05;
        int eval = 0;
        int genCount = 1;
        float *fit;

        //Generating first Population
        char **pop = generatePopulation(len, popSize);

        while (/* genCount <= 10 &&  */ eval != 1)
        {
            //Calculating fitness
            fit = generateFitness(pop, argv[1], popSize);

            //Calculating Average Fitness
            float avg = calculateAverageFitness(fit, popSize);

            //find highest fitness index
            int currbest = calcBestFitness(fit, popSize);

            printf("\nGeneration Count:\t%i", genCount);
            printf("\nCurrent Best:\t\t%s", pop[currbest]);
            printf("\nAverage Fitness:\t%.2f%%", avg);
            printf("\nTarget:\t\t\t%s\n\n", argv[1]);

            //finished cycle^

            //start of new cycle

            //Calculate Size of Mating Pool
            int mateSize = sizeMatingPool(fit, popSize);

            //Generate Mating Pool
            char **matingPool = createMatingPool(fit, pop, popSize);

            //evaluate
            eval = evaluate(pop[currbest], argv[1]);

            //ft_freetab(&pop);
            if (eval != 1)
            {
                //Generate new Generation
                pop = newGeneration(matingPool, mateSize, mutRate, popSize);
            }

            free(fit);
            //ft_freetab(&matingPool);
            genCount++;
            if (genCount > 1500)
            {
                exit(1);
            }
        }

        if (argc == 3 && strcmp(argv[2], "show") == 0)
        {

            int index = 0;
            while (index < popSize)
            {
                if (strcmp(argv[1], pop[index]) == 0)
                {
                    printf("\t\t\t\t\t\t%i:\t%s\tFitness:\t%6.2f%%\n", index + 1, pop[index], fit[index]);
                    index++;
                }
                else
                {
                    printf("%i:\t%s\tFitness:\t%6.2f%%\n", index + 1, pop[index], fit[index]);
                    index++;
                }
            }
        }
        if (argc == 3 && strcmp(argv[2], "settings") == 0)
        {
            printf("\n\nPopulation size:\t%i\nMutation Rate:\t\t%.2f\n", popSize, mutRate);
        }
    }
    else
    {
        printf("Please provide at least one argument.\n");
    }
}
