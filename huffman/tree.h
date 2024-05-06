// typedef struct _node
// {
//     char item;
//     int frequency;
//     struct _node *left;
//     struct _node *right;
// } t_node;

// typedef struct
// {
//     t_node *root;
// } t_tree;
#include "types.h"
t_tree *create_tree();
t_node *create_node(char item, int frequency);
void calc(t_list *list);
// huffman_code *create_code_list(t_node *root, int number_of_chars);

// CC = gcc
//     CFLAGS = -Wall - Wextra

//                          all : main_program

            //                        main_program : main.o tree.o list.o
            //                                       $(CC) $(CFLAGS) -
            //  o main_program main.o tree.o list.o

            //      main.o : main.c tree.h list.h types.h
            //                   $(CC) $(CFLAGS) -
            //  c - o main.o main.c

            //          list.o : list.c list.h tree.h types.h $(CC) $(CFLAGS) -
            //  c - o list.o list.c

            //          tree.o : tree.c tree.h list.h types.h $(CC) $(CFLAGS) -
            //  c - o tree.o tree.c

            //          clean : rm -
            //  f main_program *.o