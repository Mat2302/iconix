# Informações do Projeto

## Arquitetura do Projeto

A arquitetura do projeto abaixo está dividido da seguinte maneira:
- Pasta "apps":
  - Contém todos os arquivos .c: mergesort.c e mergesort_functions.c
- Pasta "include":
  - Contém os arquivos de cabeçalhos (.h) como o mergesort_functions.h
- Pasta "obj":
  - Contém os arquivos objetos .o: mergesort e mergesort_functions.o

## Explicação do Makefile

O makefile contém, atualmente, os seguintes comandos:

```gcc -c apps/mergesort_functions.c -I include/ -o obj/mergesort_functions.o```

  Executa o arquivo "mergesort_functions.c" que possui todas as funções utilizada no trabalho, com exceção da main. Essa etapa cria um arquivo objeto na pasta obj/ chamado "mergesort_functions.o" que será utilizado quando o arquivo principal (mergesort.c) ser compilado. A utilização do "-I include/" é para que o computador consiga acessar o arquivo header, que está dentro da pasta include.

```gcc apps/mergesort.c obj/mergesort_functions.o -I include/ -o obj/mergesort```

  Executa o arquivo principal do projeto, utilizando o arquivo que contém as funções do projeto (obj/mergesort_functions.o), mantendo a mesma diretriz para utilizar os arquivos de cabeçalho (.h) e criando a saída mergesort na pasta obj (obj/mergesort).

```./obj/mergesort 4 arq1.dat arq2.dat arq3.dat arq4.dat arq5.dat -o saida.dat```

  Faz a execução do programa de acordo com as instruções dadas pelo professor. Atualmente é apenas temporário, no arquivo final não estará no makefile.
