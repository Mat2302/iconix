#include "mergesort_functions.h" // Importando diretório header
#include <stdio.h>               // Biblioteca padrão de entrada e saida
#include <getopt.h>              // Biblioteca para facilitar leitura por linha de comando
#include <stdlib.h>              // Biblioteca para utilizar funções específicas
#include <string.h>              // Biblioteca para utilizar funções de manipulação de string
#include <pthread.h>

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

                // Variáveis de calculo de tempo
                struct timespec start, end;

                // Contagem de tempo de inicio
                clock_gettime(CLOCK_MONOTONIC, &start);

                // Variável que armazena o total de linhas nos arquivos de entrada
                totalNumberOfLines = contNumberOfLines(inputFile, contInputFile);

                // Vetor que armazena todos os valores do arquivo de entrada
                int *vector = vectorWithAllInputNumbers(inputFile, contInputFile, totalNumberOfLines);

                // Aloca memória para as threads conforme o número de threads desejadas.
                pthread_t *threads = malloc(numberOfThreads * sizeof(pthread_t));
                ThreadData *threadData = malloc(numberOfThreads * sizeof(ThreadData));

                // Calcular tamanho do vetor
                int sizeForEachSubVector = totalNumberOfLines / numberOfThreads;
                int remainderOfSize = totalNumberOfLines % numberOfThreads;

                for (int i = 0; i < numberOfThreads; i++)
                {
                    threadData[i].threadId = i;

                    // Caso haja valores extras, adicionará 1 valor a mais no tamanho do vetor
                    threadData[i].totalSize = sizeForEachSubVector + (i < remainderOfSize ? 1 : 0);

                    // Ajusta o deslocamento com base nos valores extras
                    threadData[i].temporaryVector = &vector[i * sizeForEachSubVector + (i < remainderOfSize ? i : remainderOfSize)];

                    if (pthread_create(&threads[i], NULL, processEachThread, &threadData[i]) != 0)
                    {
                        printf("Erro ao criar thread!\n");
                        return 1;
                    }
                }

                for (int i = 0; i < numberOfThreads; i++)
                {
                    pthread_join(threads[i], NULL);
                }

                orderOutputVector(threadData, numberOfThreads, totalNumberOfLines, optarg);

                // Libera memória alocada dinamicamente
                free(threads);
                free(threadData);
                free(inputFile);
                free(vector);

                clock_gettime(CLOCK_MONOTONIC, &end);

                double totalExecutionTime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

                printf("Tempo total de execução: %.9f segundos.\n", totalExecutionTime);

                break;
            default:
                printf("Linha de comando de entrada incorreta.\n");
                return 1;
            }
        }
    }

    return 0;
}