/* ***** Declaração de Funções ***** */
#include <stdio.h> // Biblioteca padrão de i/o para usar arquivos FILE*

void verifyNumberOfThreads(int numberOfThreads);
int contNumberOfLines(char **inputFiles, int contInputFile);
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile);
int *vectorWithAllInputNumbers(char **inputFile, int contInputFile, int totalNumberOfLines);