#include "mergesort_functions.h" // Importando diretório header
#include <stdio.h>               // Biblioteca padrão de entrada e saida
#include <getopt.h>              // Biblioteca para facilitar leitura por linha de comando
#include <stdlib.h>              // Biblioteca para utilizar funções específicas
#include <string.h>              // Biblioteca para utilizar funções de manipulação de string

int main(int argc, char *argv[])
{
    int option;
    FILE *outputFile;
    int totalNumberOfLines = 0;
    int numberOfThreads;
    int contInputFile = 0;

    // Verificação de linha de comando correta e integração do projeto
    if (argc > 1)
    {
        numberOfThreads = atoi(argv[1]);
        verifyNumberOfThreads(numberOfThreads);
        while ((option = getopt(argc, argv, ":o:")) != -1) // Verifica o comando utilizado (-o)
        {
            switch (option)
            {
            case 'o':
                outputFile = (FILE *)optarg;
                char **inputFile = saveNameOfInputFiles(&contInputFile, argc, argv, outputFile);
                if (inputFile == NULL)
                    return 1; // Erro ao alocar memória

                totalNumberOfLines = contNumberOfLines(inputFile, contInputFile); // Variável que armazena o total de linhas nos arquivos de entrada
                break;
            default:
                printf("Linha de comando de entrada incorreta.\n");
                return 1;
            }
        }
    }

    return 0;
}