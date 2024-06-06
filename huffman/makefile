CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o list.o tree.o huffman.o
	$(CC) $(CFLAGS) -o main_program main.o list.o tree.o huffman.o

main.o: main.c list.c tree.c huffman.o
	$(CC) $(CFLAGS) -c -o main.o main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c -o list.o list.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c -o tree.o tree.c

huffman.o: huffman.c huffman.h
	$(CC) $(CFLAGS) -c -o huffman.o huffman.c

clean:
	rm -f main_program *.o