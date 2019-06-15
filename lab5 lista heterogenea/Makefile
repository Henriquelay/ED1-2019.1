CC=gcc
CFLAGS=-I. -Wall  -lm -g
DEPS = listahet.h
OBJ = listahet.o proglistahet.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


ListaHet: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make clean
	mv ListaHet prog

clean:
	rm -f *.o
	rm -f prog
