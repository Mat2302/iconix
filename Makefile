
all:
	gcc -c src/mergesort_functions.c -I include/ -o obj/mergesort_functions.o
	gcc apps/mergesort.c obj/mergesort_functions.o -I include/ -o bin/mergesort
	./bin/mergesort 4 input/arq1.dat input/arq2.dat input/arq3.dat input/arq4.dat input/arq5.dat -o saida.dat