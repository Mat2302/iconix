# Definir compilador
CC=gcc
CFLAGS=-I include/

# Regra principal
all: obj mergesort

# Cria o diretório obj, caso ele não exista
obj:
	mkdir -p obj

# Linkar os arquivos objetos para criar o executável
mergesort: obj/mergesort_functions.o obj/mergesort.o
	$(CC) obj/mergesort_functions.o obj/mergesort.o -o mergesort

# Compilar mergesort_functions.c em mergesort_functions.o
obj/mergesort_functions.o: apps/mergesort_functions.c include/mergesort_functions.h | obj
	$(CC) -c apps/mergesort_functions.c $(CFLAGS) -o obj/mergesort_functions.o

# Compilar mergesort.c (contendo a main) em mergesort.o
obj/mergesort.o: apps/mergesort.c include/mergesort_functions.h | obj
	$(CC) -c apps/mergesort.c $(CFLAGS) -o obj/mergesort.o

# Limpeza dos arquivos objetos
clean:
	rm -f obj/*.o mergesort