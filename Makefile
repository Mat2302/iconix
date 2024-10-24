# Definir compilador
CC=gcc

# Definir compilação de arquivo "main"
obj/mergesort: obj/mergesort_functions.o
	$(CC) obj/mergesort_functions.o -o mergesort

# Definir compilação de arquivo com funções
obj/mergesort_functions.o: ../apps/mergesort_functions.c ../include/mergesort_functions.h
	$(CC) -c ../apps/mergesort_functions.c -o obj/mergesort_functions.o