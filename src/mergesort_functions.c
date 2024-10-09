#include "mergesort_functions.h" // Importando diretório header
#include <stdio.h> // Biblioteca padrão de entrada/saída
#include <stdlib.h> // Biblioteca para funções específicas
#include <string.h> // Biblioteca para utilizar funções de manipulação de string
#define TBF 1000 // Define tamanho base para o buffer(quantidade de caracteres em uma linha)

// Função que verifica o número de threads requisitadas pelo usuário
void verifyNumberOfThreads(int numberOfThreads)
{
    if ((numberOfThreads != 2) && (numberOfThreads != 4) && (numberOfThreads != 8))
    {
        printf("Número de threads requisitados incorreto, os valores de threads disponíveis são: 2, 4 ou 8.\n");
    }
}

// Função que verifica o número de linhas de um arquivo para declarar depois no malloc
int contNumberOfLines(char *fileName)
{
    char buffer[TBF]; // Buffer temporário para armazenar o conteúdo de cada linha
    int numberOfLines = 0; // Variável para armazenar a quantidade de elementos lidos dos arquivos de entrada

    FILE *arq = fopen(fileName, "r");
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    // Ler cada linha e incrementar a variável numberOfLines
    while(fgets(buffer, sizeof(buffer), arq) != NULL)
    {
        numberOfLines++;
    }

    fclose(arq);
    return numberOfLines;
}

// Função que ordena um arquivo e coloca no arquivo de saida
void sortFile(char *fileName, int *numberLines, char *outputFile)
{
    FILE *arq;
    arq = fopen(fileName, "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    int *vetor = (int *)malloc(*numberLines * sizeof(int));

    for (int i = 0; i < *numberLines; i++)
    {
        fscanf(arq, "%d", &vetor[i]);
    }

    fclose(arq);

    //mergeSort(vetor, 0, *numberLines - 1);

    arq = fopen(outputFile, "w");

    for (int i = 0; i < *numberLines; i++)
    {
        fprintf(arq, "%d\n", vetor[i]);
    }

    fclose(arq);
}

// Função para ler o arquivo de entrada
void readFile(char *fileName)
{
    FILE *arq;
    arq = fopen(fileName, "a");
}

// Função que armazena o nome dos arquivos de entrada
char **saveNameOfInputFiles(int *contInputFile, int argc, char *argv[], FILE *outputFile)
{
    *contInputFile = 0;
    char **inputFile = malloc((argc - 3) * sizeof(char*)); // Aloca memória de acordo com a quantidade de arquivos de entrada digitado na linha de comando
    if(inputFile == NULL)
    {
        printf("Erro ao alocar memória dinamicamente!\n");
        return NULL;
    }

    for(int i = 2; i < argc; i++)
    {
        // Ignora as posições que contenham como conteúdo "-o" e o arquivo de saida (saida.dat)
        if((strcmp(argv[i], "-o") == 0) || (strcmp(argv[i], (char*) outputFile) == 0))
        {
            continue;
        }

        // Caso encontre os arquivos de entrada (extensão .dat ou .txt), armazenará o nome no arquivo criado de forma dinâmica
        if((strstr(argv[i], ".dat") != NULL) || (strstr(argv[i], ".txt") != NULL))
        {
            inputFile[*contInputFile] = argv[i];
            (*contInputFile)++;
        }
    }

    return inputFile; // Retorna o arquivo criado dinamicamente com o nome dos arquivos de entrada
}