#ifndef TREE_H
#define TREE_H

#include "types.h"

t_tree *create_tree();
void print_tree(t_node *node, int qtd);
void free_node(t_node *node);
void clear_tree(t_tree *tree);
void destroy_tree(t_tree *tree);

#endif // TREE_H