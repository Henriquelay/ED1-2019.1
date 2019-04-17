CC=gcc
CFLAGS=-I. -Wall  -lm -g
DEPS = listaencadeada.h
OBJ = proglista_produto.o listaencadeada.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


ListaProduto: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make clean
	mv ListaProduto prog

clean:
	rm -f *.o
	rm -f prog
