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



                // Apenas alguns testes
                int inputFilesForEachThread = contInputFile / numberOfThreads;
                int leftInputFiles = contInputFile % numberOfThreads;

                pthread_t *threads = malloc(numberOfThreads * sizeof(pthread_t));
                ThreadData *threadData = malloc(contInputFile * sizeof(ThreadData)); // Struct de cada thread, quantidade é o número informado pelo usuário

                for(int i = 0; i < contInputFile; i++)
                {
                    threadData[i].inputFile = inputFile[i];
                    threadData[i].threadId = i;

                    if(pthread_create(&threads[i], NULL, processEachThread, &threadData[i]) != 0)
                    {
                        printf("Erro ao criar a thread %d\n", i);
                        free(threads);
                        free(threadData);
                        return 1;
                    }
                }

                for(int i = 0; i < contInputFile; i++)
                {
                    pthread_join(threads[i], NULL);
                }

                printf("Processamento concluído!\n");

                free(threads);
                free(threadData);

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