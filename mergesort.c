#include <stdio.h>  // Biblioteca padrão de entrada e saida
#include <getopt.h> // Biblioteca para facilitar leitura por linha de comando
#include <stdlib.h> // Biblioteca para utilizar funções específicas (atoi)
#include <string.h> // Biblioteca para utilizar funções de manipulação de string

void verifyNumberOfThreads(int numberOfThreads);

int main(int argc, char *argv[])
{
    int option;
    int numberOfThreads;
    char *inputFile;
    char *outputFile;

    // Verificação de linha de comando correta e integração do projeto
    if (argc > 1)
    {
        numberOfThreads = atoi(argv[1]);
        verifyNumberOfThreads(numberOfThreads);
        while ((option = getopt(argc, argv, ":o:")) != -1)
        {

            switch (option)
            {
            case 'o':
                printf("A opção o foi identificada.\n");
                printf("Argumento da opção o: %s\n", optarg);
                break;
            }
        }
    }
    else
    {
        printf("Linha de comando de entrada incorreta.\n");
        return 1;
    }

    int *numberLines = 0;

    // Leitura dos arquivos da linha de comando
    for (int i = 2; i < argc; i++)
    {
        // Ignora o -o e o arquivo de saída
        if (strcamp(arqv[i] == "-o") == 0 || strcamp(arqv[i] == outputFile) == 0)
        {
            continue;
        }

        verifyNumberofLines(arqv[i], &numberLines);
        ordenaArquivo(arqv[i], &numberLines, &outputFile)
    }
    return 0;
}

// Função que verifica o número de threads requisitadas pelo usuário
void verifyNumberOfThreads(int numberOfThreads)
{
    if ((numberOfThreads != 2) && (numberOfThreads != 4) && (numberOfThreads != 8))
    {
        printf("Número de threads requisitados incorreto, os valores de threads disponíveis são: 2, 4 ou 8.\n");
    }
}

// Função que verifica o número de linhas de um arquivo para declarar depois no malloc
void verifyNumberofLines(char *arqName, int *numberLines)
{
    *numberLines = 0;   

    FILE *arq;
    arq = fopen(arqName, "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(arq) != NULL)
    {
        *numberLines++;
    }
}

// Função que ordena um arquivo e coloca no arquivo de saida
void ordenaArquivo(char *arqName, int *numberLines, char *outputFile)
{
    FILE *arq;
    arq = fopen(arqName, "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int *vetor = (int *)malloc(*numberLines * sizeof(int));

    for (int i = 0; i < *numberLines; i++)
    {
        fscanf(arq, "%d", &vetor[i]);
    }

    fclose(arq);

    mergeSort(vetor, 0, *numberLines - 1);

    arq = fopen(outputFile, "w");

    for (int i = 0; i < *numberLines; i++)
    {
        fprintf(arq, "%d\n", vetor[i]);
    }

    fclose(arq);
}

void readFile(char *arqName)
{
    FILE *arq;
    arq = fopen(arqName, "a");
}