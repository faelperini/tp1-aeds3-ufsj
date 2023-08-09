#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "files.h"
#include "points.h"

void openFiles(int argc, char **argv, char *Input, char *Output){ 
    int getop;

    while((getop = getopt(argc, argv, "i:o:")) != -1) {
        if (getop == 'i') {
            strcpy(Input, optarg);
        } else if (getop == 'o') {
            strcpy(Output, optarg);
        } else {
            fprintf(stderr, "Entrada invalida! \n");
            break;
        }
    }
}

void readFiles(char *Input) { 
    FILE *entrada = fopen(Input, "r");
    fscanf(entrada, "%d %f %f", &Npoints, &A, &B);

    if((Npoints > MAX_P) || A >= B || B > 10000 || A < 0) {
        printf("Arquivo de entrada invalido! \n");
        exit(0);
    }

    points = (Point *)malloc(Npoints * sizeof(Point));
    for(int i = 0; i < Npoints; i++) {
        fscanf(entrada, "%f %f\n", &(points[i]).x, &(points[i].y));
    }

    fclose(entrada);
}