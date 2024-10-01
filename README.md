# Funções do programa

## Informações sobre o projeto

- Ler N arquivos de entrada contendo:
  - Valores inteiros não ordenados, 1000 valores (não limitado, o programa deve trabalhar com quaisquer tamanhos de arquivos)
  - Os valores podem estar repetidos ou não.
- Ordenar os valores dos arquivos anteriores em ordem crescente
- Após ordenar os valores, enviá-los para um arquivo de saída.

- O programa deve funcionar para T threads:
  - T pode ser 2, 4 ou 8
  - A quantidade de threads utilizada não pode ultrapassar o valor de T
  - O programa deve usar a quantidade máxima de threads possível.

## Entrada e saída do programa

- Os valores de entrada deverão ser passados por parâmetros a partir da linha de comando quando for executar o código
- Entrada:
  - número de threads que o sistema deverá utilizar (T)
  - nomes dos arquivos de entrada
  - nome do arquivo de saída
    - Para os testes, considere que haverão 5 arquivos de entrada com 1000 valores cada.
- Exemplo de entrada:
  - ./mergesort 4 arq1.dat arq2.dat arq3.dat -o saida.dat
    - ./mergesort é o nome do programa;
    - 4 é o número de threads;
    - arq1.dat arq2.dat arq3.dat são os arquivos de entrada
    - -o saida.dat indica o arquivo que contém os dados de saída
- Saída:
  - exibir o tempo de execução de cada thread
    - tempo de execução de cada thread:
      - contado a partir do início daquele thread até o final dele (dentro do thread).
      - o tempo total de execução de todos os threads considera o tempo de criação dos threads de processamento até a finalização de todo o conjunto.
  - exibir o tempo total de execução do sistema

## Informações importantes

- Todos os vetores deverão ser alocados dinamicamente (utilizando malloc)
- O programa deve compilar sem erros
  - Criar um *makefile* ou *script* para a compilação
- Os dados devem estar armazenados também em arquivos texto, arquivos de saída também deverão ser criados dessa maneira.
- Utilizar a linha de comando indicada acima, inclusive o nome do programa.

## Produtos do projeto a serem entregados

- Código fonte em C, completo, documentado e pronto para ser executado em sistema Linux.
  - Criar arquivo *makerfile*.
- Relatório contendo a descrição do problema; instruções para compilar o programa; gráficos com o tempo de execução dos experimentos; conclusões a respeito dos resultados obtidos.
  - Formato PDF.
- Vídeo mostrando o código fonte do programa, compilação do programa, trechos dos arquivos de entrada e as execuções do programa para os experimentos.
  - Gravar a tela e postar o vídeo em site que o professor possa acessar.

