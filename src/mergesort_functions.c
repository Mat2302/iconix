#include "mergesort_functions.h" // Importando diretório header
#include <stdio.h> // Biblioteca padrão de entrada/saída
#include <stdlib.h> // Biblioteca para funções específicas
#include <string.h> // Biblioteca para utilizar funções de manipulação de string

// Função que verifica o número de threads requisitadas pelo usuário
void verifyNumberOfThreads(int numberOfThreads)
{
    if ((numberOfThreads != 2) && (numberOfThreads != 4) && (numberOfThreads != 8))
    {
        printf("Número de threads requisitados incorreto, os valores de threads disponíveis são: 2, 4 ou 8.\n");
    }
}

// Função que verifica o número de linhas de um arquivo para declarar depois no malloc
void verifyNumberOfLines(char *arqName, int *numberLines)
{
    *numberLines = 0;   

    FILE *arq;
    arq = fopen(arqName, "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }

    // while (fgets(arq) != NULL)
    // {
    //     *numberLines++;
    // }
}

// Função que ordena um arquivo e coloca no arquivo de saida
void sortFile(char *arqName, int *numberLines, char *outputFile)
{
    FILE *arq;
    arq = fopen(arqName, "r");

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
void readFile(char *arqName)
{
    FILE *arq;
    arq = fopen(arqName, "a");
}