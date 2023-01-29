#compiler settings
CC = gcc
CFLAGS = -Wall -g
LIBS = image.c file.c util.c -lm

#functions

all:
	$(CC) $(CFLAGS) -o pgmnega pgmnega.c $(LIBS)
	$(CC) $(CFLAGS) -o pgmrotacao pgmrotacao.c $(LIBS)
	$(CC) $(CFLAGS) -o pgmlimiar pgmlimiar.c $(LIBS)
	$(CC) $(CFLAGS) -o pgmmedia pgmmedia.c $(LIBS)

clean:
	rm -f *.o 

purge: clean
	rm -f pgmnega pgmrotacao pgmlimiar pgmmedia
