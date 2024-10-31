/* ***** Declaração de Funções ***** */
#include <stdio.h>
#include <pthread.h>

typedef struct 
{
    int threadId;
    int startIndex;
    int endIndex;
    int *temporaryVector;
} ThreadData;

void *processEachThread();
int compare(const void *a, const void *b);
void verifyNumberOfThreads(int numberOfThreads);
void orderNumbers(int *vectorToChange, int size);
int* addAllVector(int* vector, int totalNumberOfLines);
int contNumberOfLines(char **inputFiles, int contInputFile);
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile);
int *vectorWithAllInputNumbers(char **inputFile, int contInputFile, int totalNumberOfLines);
void addInputNumbersToOutputFile(int *inputNumbers, int totalNumberOfLines, char* nameOfOutputFile);
