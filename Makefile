
CC = gcc -Wall -c

twc listaEnlazada: twc.o listaEnlazada.o
	gcc obj/twc.o -o bin/twc -pthread -lm
	gcc obj/listaEnlazada.o -o bin/listaEnlazada -pthread


twc.o: src/twc.c
	$(CC) src/twc.c -o obj/twc.o -pthread -lm

listaEnlazada.o: src/listaEnlazada.c
	$(CC) src/listaEnlazada.c -o obj/listaEnlazada.o -pthread


clean: 
	rm bin/* obj/*