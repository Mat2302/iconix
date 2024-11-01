/* ***** Declaração de Funções ***** */
#include <stdio.h>
#include <pthread.h>

typedef struct 
{
    int threadId;
    int totalSize;
    int *temporaryVector;
} ThreadData;

void *processEachThread();
int compare(const void *a, const void *b);
int* addAllVector(int* vector, int totalNumberOfLines);
int contNumberOfLines(char **inputFiles, int contInputFile);
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile);
int *vectorWithAllInputNumbers(char **inputFile, int contInputFile, int totalNumberOfLines);
void addInputNumbersToOutputFile(int *inputNumbers, int totalNumberOfLines, char* nameOfOutputFile);
void orderOutputVector(ThreadData *data, int numberOfThreads, int totalNumberOfLines, char *outputFile);
