#ifndef TYPES_H
#define TYPES_H

typedef struct _node
{
    char item;
    char *path;
    int frequency;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct
{
    t_node *root;
    int number_of_chars;
} t_tree;

typedef struct
{
    char item;
    char *code;
    int frequency;
} huffman_code;

typedef struct
{
    huffman_code **items;
    int size;
} huffman_list;

typedef struct
{
    t_node **items;
    int size;
} t_list;

#endif // TYPES_H