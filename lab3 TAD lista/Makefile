CC=gcc
CFLAGS=-I. -Wall  -lm
DEPS = listaproduto.h
OBJ = listaproduto.o maindeteste.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

maindeteste: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f *.o
	mv maindeteste listaproduto


clean:
	rm -f *.o
	rm -f listaproduto
