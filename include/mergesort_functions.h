/* ***** Declaração de Funções ***** */
#include <stdio.h>
#include <pthread.h>

typedef struct 
{
    // int threadId;
    // char **inputFile;
    // int *temporaryVector;
    // int numberOfInputFiles;
    // int temporaryVectorSize;

    int threadId;
    int startIndex;
    int endIndex;
    int *temporaryVector;
} ThreadData;

void *processEachThread();
void verifyNumberOfThreads(int numberOfThreads);
int* addAllVector(int* vector, int totalNumberOfLines);
int contNumberOfLines(char **inputFiles, int contInputFile);
int *orderNumbers(int *vetorOfNumber, int startIndex, int endIndex);
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile);
int *vectorWithAllInputNumbers(char **inputFile, int contInputFile, int totalNumberOfLines);
void addInputNumbersToOutputFile(int *inputNumbers, int totalNumberOfLines, char* nameOfOutputFile);
