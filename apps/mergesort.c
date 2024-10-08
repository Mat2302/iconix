#include "mergesort_functions.h" // Importando diretório header
#include <stdio.h>  // Biblioteca padrão de entrada e saida
#include <getopt.h> // Biblioteca para facilitar leitura por linha de comando
#include <stdlib.h> // Biblioteca para utilizar funções específicas
#include <string.h> // Biblioteca para utilizar funções de manipulação de string

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
        if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], outputFile) == 0)
        {
            continue;
        }

        verifyNumberOfLines(argv[i], &numberLines);
        sortFile(argv[i], &numberLines, &outputFile);
    }
    return 0;
}