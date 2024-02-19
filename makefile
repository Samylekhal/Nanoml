CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: projet

projet: projet.o arbre.o analyse.o
	$(CC) -o projet projet.o arbre.o analyse.o

projet.o: projet.c 
	$(CC) -c $(CFLAGS) projet.c

arbre.o: arbre.c arbre.h
	$(CC) -c $(CFLAGS) arbre.c

analyse.o: analyse.c analyse.h
	$(CC) -c $(CFLAGS) analyse.c


clean:
	rm -f projet projet.o arbre.o analyse.o
