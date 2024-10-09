
all:
	gcc -c src/mergesort_functions.c -I include/ -o obj/mergesort_functions.o
	gcc apps/mergesort.c obj/mergesort_functions.o -I include/ -o bin/mergesort
	./bin/mergesort 4 arq1.dat arq2.dat -o saida.dat