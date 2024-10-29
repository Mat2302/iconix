/* ***** Declaração de Funções ***** */
#include <stdio.h> // Biblioteca padrão de i/o para usar arquivos FILE*

typedef struct 
{
    int threadId;
    char *inputFile;
    int numberOfInputFile;
    int sizeOfEachThreadVector;
} ThreadData;

void *processEachThread();
void verifyNumberOfThreads(int numberOfThreads);
int contNumberOfLines(char **inputFiles, int contInputFile);
void orderNumbers(int *vetorOfNumber, int totalNumberOfLines, char* nameOfOutputFile);
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile);
int *vectorWithAllInputNumbers(char **inputFile, int contInputFile, int totalNumberOfLines);
void addInputNumbersToOutputFile(int *inputNumbers, int totalNumberOfLines, char* nameOfOutputFile);
