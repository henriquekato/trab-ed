CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o tree.o
	$(CC) $(CFLAGS) -o main_program main.o tree.o

main.o: main.c tree.h
	$(CC) $(CFLAGS) -c -o main.o main.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c -o tree.o tree.c

clean:
	rm -f main_program *.o