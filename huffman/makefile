CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o types.o
	$(CC) $(CFLAGS) -o main_program main.o types.o

main.o: main.c types.h
	$(CC) $(CFLAGS) -c -o main.o main.c

types.o: types.c types.h
	$(CC) $(CFLAGS) -c -o types.o types.c

clean:
	rm -f main_program *.o