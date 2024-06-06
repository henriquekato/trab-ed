#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "types.h"

void node_path(t_node *node, char *path);
huffman_code *create_code(t_node *node);
void pre_order(t_node *node, huffman_list *code_list);
huffman_list *create_huffman_list(t_tree *tree);
huffman_list *create_code_list(t_tree *tree);
void print_huffman(huffman_list *code_list);
void clear_code_list(huffman_list *code_list);
void destroy_code_list(huffman_list *code_list);
void dec(char *sequence, huffman_list *code_list);
void cod(char *sequence, huffman_list *code_list);

#endif // HUFFMAN_H