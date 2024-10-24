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
        // Armazena o número de threads a partir da linha de comando
        numberOfThreads = atoi(argv[1]);
        
        // Verifica se o número de threads solicitadas está correto
        verifyNumberOfThreads(numberOfThreads);

        // Verificação e execução da linha de comando
        while ((option = getopt(argc, argv, ":o:")) != -1)
        {
            switch (option)
            {
            case 'o':
                // Captura o nome do arquivo de saída
                outputFile = (FILE *)optarg;
                
                // Cria um vetor dinamico com o nome dos arquivos de entrada
                char **inputFile = saveNameOfInputFiles(&contInputFile, argc, argv, outputFile);
                
                // Cria arquivo de saída com o nome digitado na linha de comando
                outputFile = fopen(optarg, "w+"); 
                
                // Erro ao alocar memória
                if (inputFile == NULL)
                {
                    return 1;
                }

                // Variável que armazena o total de linhas nos arquivos de entrada
                totalNumberOfLines = contNumberOfLines(inputFile, contInputFile);
                
                // Vetor que armazena todos os valores do arquivo de entrada
                int *vector = vectorWithAllInputNumbers(inputFile, contInputFile, totalNumberOfLines);
                
                // Orderna os valores em ordem crescente
                orderNumbers(vector, totalNumberOfLines, optarg);
                
                // Libera memória alocada dinamicamente
                free(inputFile);
                free(vector);

                break;
            default:
                printf("Linha de comando de entrada incorreta.\n");
                return 1;
            }
        }
    }

    return 0;
}