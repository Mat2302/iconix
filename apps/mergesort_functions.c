#include "mergesort_functions.h" // Importando diretório header
#include <stdio.h>               // Biblioteca padrão de entrada/saída
#include <stdlib.h>              // Biblioteca para funções específicas
#include <string.h>              // Biblioteca para utilizar funções de manipulação de string
#include <pthread.h>             // Biblioteca para utilizar threads
#include <time.h>                // Biblioteca para cálculo de tempo

// Função que verifica o número de linhas de um arquivo para declarar depois no malloc
int contNumberOfLines(char **inputFile, int contInputFile)
{
    int bufferSizeAllocation = 5000;
    char *buffer = malloc(bufferSizeAllocation * sizeof(int));

    int numberOfLines = 0; // Variável para armazenar a quantidade de elementos lidos dos arquivos de entrada

    for (int i = 0; i < contInputFile; i++)
    {
        FILE *arq = fopen(inputFile[i], "r");

        if (arq == NULL)
        {
            printf("Erro ao abrir arquivo %s!\n", inputFile[i]);
            continue;
        }

        // Le cada linha do arquivo e incrementa em numberOfLines
        while (fgets(buffer, sizeof(buffer), arq) != NULL)
        {
            numberOfLines++;
        }

        fclose(arq);
    }

    free(buffer);

    return numberOfLines;
}

// Função que armazena o nome dos arquivos de entrada
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile)
{
    *contInputFile = 0;
    char **inputFile = malloc((argc - 3) * sizeof(char *)); // Aloca memória de acordo com a quantidade de arquivos de entrada digitado na linha de comando
    if (inputFile == NULL)
    {
        printf("Erro ao alocar memória dinamicamente!\n");
        return NULL;
    }

    for (int i = 2; i < argc; i++)
    {
        // Ignora as posições que contenham como conteúdo "-o" e o arquivo de saida (saida.dat)
        if ((strcmp(argv[i], "-o") == 0) || (strcmp(argv[i], (char *)outputFile) == 0))
        {
            continue;
        }

        // Caso encontre os arquivos de entrada (extensão .dat ou .txt), armazenará o nome no arquivo criado de forma dinâmica
        if ((strstr(argv[i], ".dat") != NULL) || (strstr(argv[i], ".txt") != NULL))
        {
            inputFile[*contInputFile] = argv[i];
            (*contInputFile)++;
        }
    }

    return inputFile; // Retorna o arquivo criado dinamicamente com o nome dos arquivos de entrada
}

int *vectorWithAllInputNumbers(char **inputFile, int contInputFile, int totalNumberOfLines)
{
    int index = 0;                                                                // Index que armazena os valores do vetor
    int *vectorWithInputValues = (int *)malloc(totalNumberOfLines * sizeof(int)); // Vetor para alocar os valores de entrada

    if (vectorWithInputValues == NULL)
    {
        printf("Erro ao alocar memória dinamicamente!\n");
        return NULL;
    }

    // Loop para cada arquivo de entrada
    for (int i = 0; i < contInputFile; i++)
    {
        FILE *arq = fopen(inputFile[i], "r");

        if (arq == NULL)
        {
            printf("Erro ao abrir o arquivo %s!\n", inputFile[i]);
            continue;
        }

        // Lê os valores dos arquivos de entrada e armazena no vetor dinâmico
        while (fscanf(arq, "%d", &vectorWithInputValues[index]) == 1)
        {
            index++;
        }

        fclose(arq);
    }

    return vectorWithInputValues; // Retorna o vetor de vetores preenchido
}

// Adiciona os valores dos arquivos de entrada no arquivo de saida
void addInputNumbersToOutputFile(int *inputNumbers, int totalNumberOfLines, char *nameOfOutputFile)
{
    FILE *arq;
    arq = fopen(nameOfOutputFile, "w+");

    // Percorre o vetor e printa o valor no arquivo de saída
    for (int i = 0; i < totalNumberOfLines; i++)
    {
        fprintf(arq, "%d\n", inputNumbers[i]);
    }

    fclose(arq);
}

// Função auxiliar para qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Atribui os arquivos de entrada a cada thread
void *processEachThread(void *args)
{
    ThreadData *data = (ThreadData *)args;

    struct timespec start, end;

    // Captura o tempo de inicio de execução da thread
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Ordenar cada vetor em ordem crescente
    qsort(data->temporaryVector, data->totalSize, sizeof(int), compare);

    // Captura o tempo de término de execução da thread
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calcula tempo de execução em segundos
    double totalTime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Imprimindo o tempo na tela
    printf("Thread %d executou em %.9f segundos\n", data->threadId, totalTime);
    
    pthread_exit(NULL);
}

// É O FIM!!
void orderOutputVector(ThreadData *threadData, int numberOfThreads, int totalNumberOfLines, char *outputFile)
{
    int *vector = (int *)(malloc(totalNumberOfLines*sizeof(int)));
    int pos = 0; 


    for (int i = 0; i < numberOfThreads; i++)
    {
        for (int j = 0; j < threadData[i].totalSize; j++)
        {
            vector[pos++] = threadData[i].temporaryVector[j];
        }
    }

    qsort(vector, totalNumberOfLines, sizeof(int), compare);

    addInputNumbersToOutputFile(vector, totalNumberOfLines, outputFile);
}