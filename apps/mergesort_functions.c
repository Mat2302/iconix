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
int contNumberOfLines(char **inputFile, int contInputFile)
{
    char buffer[TBF]; // Buffer temporário para armazenar o conteúdo de cada linha
    int numberOfLines = 0; // Variável para armazenar a quantidade de elementos lidos dos arquivos de entrada

    for(int i = 0; i < contInputFile; i++)
    {
        FILE *arq = fopen(inputFile[i], "r");
        
        if(arq == NULL)
        {
            printf("Erro ao abrir arquivo %s!\n", inputFile[i]);
            continue;
        }

        // Le cada linha do arquivo e incrementa em numberOfLines
        while(fgets(buffer, sizeof(buffer), arq) != NULL)
        {
            numberOfLines++;
        }

        fclose(arq);
    }
    
    return numberOfLines;
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

int *vectorWithAllInputNumbers(char **inputFile, int contInputFile, int totalNumberOfLines)
{
    int index = 0; // Index que armazena os valores do vetor
    int *vectorWithInputValues = (int *)malloc(totalNumberOfLines * sizeof(int)); // Vetor para alocar os valores de entrada

    if (vectorWithInputValues == NULL)
    {
        printf("Erro ao alocar memória dinamicamente!\n");
        return NULL;
    }

    // Loop para cada arquivo de entrada
    for(int i = 0; i < contInputFile; i++)
    {
        FILE *arq = fopen(inputFile[i], "r");
        
        if(arq == NULL)
        {
            printf("Erro ao abrir o arquivo %s!\n", inputFile[i]);
            continue;
        }

        // Lê os valores dos arquivos de entrada e armazena no vetor dinâmico
        while(fscanf(arq, "%d", &vectorWithInputValues[index]) == 1)
        {
            index++;
        }

        fclose(arq);
    }

    return vectorWithInputValues; // Retorna o vetor de vetores preenchido
}

// Adiciona os valores dos arquivos de entrada no arquivo de saida
void addInputNumbersToOutputFile(int *inputNumbers, int totalNumberOfLines, char* nameOfOutputFile)
{
    FILE* arq;
    arq = fopen(nameOfOutputFile, "w+");

    // Percorre o vetor e printa o valor no arquivo de saída
    for(int i = 0; i < totalNumberOfLines; i++)
    {
        fprintf(arq, "%d\n", inputNumbers[i]);
    }

    fclose(arq);

}

//Ordernar valores em ordem crescente
void orderNumbers(int *vetorOfNumber, int totalNumberOfLines, char* nameOfOutputFile){
    int temp = 1000000000;
    int posTemp = 0;
    int pos = 0;

    int *auxVector = (int*)(malloc(totalNumberOfLines * sizeof(int)));

    while(pos < totalNumberOfLines)
    {
        temp = 1000000000;
        for(int i = 0; i < totalNumberOfLines; i++)
        {
            if (vetorOfNumber[i] != -1)
            {
                if(vetorOfNumber[i] < temp)
                {
                    temp = vetorOfNumber[i];
                    posTemp = i;
                }
            }
        }
        
        vetorOfNumber[posTemp] = -1;
        auxVector[pos] = temp;
        pos++;
    }

    addInputNumbersToOutputFile(auxVector,totalNumberOfLines,nameOfOutputFile);

    free(auxVector);
}
