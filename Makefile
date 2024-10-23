
all:
	gcc -c apps/mergesort_functions.c -I include/ -o obj/mergesort_functions.o
	gcc apps/mergesort.c obj/mergesort_functions.o -I include/ -o obj/mergesort
	./obj/mergesort 4 arq1.dat arq2.dat arq3.dat arq4.dat arq5.dat -o saida.dat