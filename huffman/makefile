CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o tree.o list.o
	$(CC) $(CFLAGS) -o main_program main.o tree.o list.o

main.o: main.c tree.h list.h
	$(CC) $(CFLAGS) -c -o main.o main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c -o list.o list.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c -o tree.o tree.c

clean:
	rm -f main_program *.o