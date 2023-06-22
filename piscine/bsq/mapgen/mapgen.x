#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    int         nsize;
    int         density;
    FILE        *fp;
    const char  empty = '.';
    const char  obst = 'o';
    const char  full = 'x';

    if (argc != 4)
    {
        printf("Invalid Params. Three required params are: N, D and Filename\n");
        printf("N is the size of the map\n");
        printf("D is the percentage of total squares used as obstacles\n");
        printf("Example: 1000 20 test00.txt\n");
        return (1);
    }
    sscanf(argv[1], "%d", &nsize);
    sscanf(argv[2], "%d", &density);

    fp = fopen(argv[3], "w");
    if (fp == NULL)
    {
        printf("Error while writing to the file!\n");
        return (1);
    }

    srand(time(NULL));
    fprintf(fp, "%d%c%c%c\n", nsize, empty, obst, full);
    for (int i = 0; i < nsize; i++)
    {
        for (int j = 0; j < nsize; j++)
            if (rand() % 100 < density)
                fprintf(fp, "%c", obst);
            else
                fprintf(fp, "%c", empty);
        fprintf(fp, "\n");
    }
    fclose(fp);
    return (0);
}