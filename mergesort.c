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