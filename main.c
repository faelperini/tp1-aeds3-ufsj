#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <math.h>
#include "files.h"
#include "points.h"

int main(int argc, char **argv) {

    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    
    char *Input = (char *)malloc(MAX_P*sizeof(char));
    char *Output = (char *)malloc(MAX_P*sizeof(char));

    openFiles(argc, argv, Input, Output);
    readFiles(Input);
    solve();

    FILE *saida = fopen(Output,"a");
    fprintf(saida, "%d\n",result);
    fclose(saida);

    gettimeofday(&end_time, NULL);
    double exec_time = (end_time.tv_sec - start_time.tv_sec) + 
                       (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    double mem_used = r_usage.ru_maxrss / 1024.0;

    printf("Maior = %d\n", result);
    printf("Memória utilizada: %lf KB\n", mem_used);
    printf("Tempo de execução: %lf segundos\n", exec_time);

    free(Input);
    free(Output);
    free(points);
}