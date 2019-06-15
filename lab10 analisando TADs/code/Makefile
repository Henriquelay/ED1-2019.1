CC=gcc
CFLAGS=-I. -Wall  -lm
DEPS = listaencadeada.h ArvoreBinaria.h ArvoreAVL.h
OBJLISTA = testLista.o listaencadeada.o

OBJARV = testArvoreBinaria.o ArvoreBinaria.o

OBJAVL = testArvoreAVL.o ArvoreAVL.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


DesempenhoLista: $(OBJLISTA)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f *.o

DesempenhoArvore: $(OBJARV)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f *.o

DesempenhoAVL: $(OBJAVL)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f *.o

all: DesempenhoLista DesempenhoArvore DesempenhoAVL
	rm -f *.o

clean:
	rm -f DesempenhoLista
	rm -f DesempenhoArvore
	rm -f DesempenhoAVL
	rm -f *.o
