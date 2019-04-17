CC=gcc
CFLAGS=-I. -Wall  -lm
DEPS = listaencadeada.h
OBJ = proglista_produto.o listaencadeada.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


ListaProduto: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
