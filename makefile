CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: projet

projet: projet.o arbre.o analyse.o Interpretation.o
	$(CC) -o projet projet.o arbre.o analyse.o Interpretation.o

projet.o: projet.c 
	$(CC) -c $(CFLAGS) projet.c

arbre.o: arbre.c 
	$(CC) -c $(CFLAGS) arbre.c

analyse.o: analyse.c 
	$(CC) -c $(CFLAGS) analyse.c

Interpretation.o: Interpretation.c 
	$(CC) -c $(CFLAGS) Interpretation.c


clean:
	rm -f projet projet.o arbre.o analyse.o
