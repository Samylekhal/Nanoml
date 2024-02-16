CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: projet

projet: projet.o arbre.o
	$(CC) -o projet projet.o arbre.o

projet.o: projet.c arbre.h
	$(CC) -c $(CFLAGS) projet.c

arbre.o: arbre.c arbre.h
	$(CC) -c $(CFLAGS) arbre.c

clean:
	rm -f projet projet.o arbre.o
