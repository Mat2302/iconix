# Informações do Projeto

## Arquitetura do Projeto

A arquitetura do projeto abaixo está dividido da seguinte maneira:
- Pasta "apps":
  - Contém todos os arquivos .c: mergesort.c e mergesort_functions.c
- Pasta "include":
  - Contém os arquivos de cabeçalhos (.h) como o mergesort_functions.h
- Pasta "obj":
  - Contém os arquivos objetos .o: mergesort e mergesort_functions.o

## Instruções para uso

1. É necessário fazer o ```git clone``` ou o download do arquivo no seu diretório.
2. Acesse a pasta do repositório.
3. Utilize o comando ```make all``` para que sejam gerados todos os arquivos objeto e que o arquivo executável seja gerado.
4. Utilize o comando desejado, segue um exemplo abaixo:
   
  ```./mergesort 4 arq1.dat arq2.dat arq3.dat arq4.dat arq5.dat -o saida.dat```
  
1. Caso queira, poderá utilizar o comando ```make clean``` para remover os arquivos objeto e o executável do computador, porém saiba que casao queira executar o projeto novamente, terá que seguir o passo 3 novamente.