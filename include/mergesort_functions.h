/* ***** Declaração de Funções ***** */
#include <stdio.h> // Biblioteca padrão de i/o para usar arquivos FILE*

void readFile(char *fileName);
int contNumberOfLines(char **inputFiles, int contInputFile);
void verifyNumberOfThreads(int numberOfThreads);
void sortFile(char *fileName, int *numberLines, char *outputFile);
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile);