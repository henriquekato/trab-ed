CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o t_stack.o
	$(CC) $(CFLAGS) -o main_program main.o t_stack.o

main.o: main.c t_stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

t_stack.o: t_stack.c t_stack.h
	$(CC) $(CFLAGS) -c -o t_stack.o t_stack.c

clean:
	rm -f main_program *.o