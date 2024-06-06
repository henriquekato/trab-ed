#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

t_tree *create_tree()
{
    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));
    if (!tree)
        return NULL;
    tree->root = NULL;
    tree->number_of_chars = 0;
    return tree;
}

void print_tree(t_node *node, int qtd)
{
    if (node == NULL)
        return;
    print_tree(node->right, qtd + 1);
    for (int i = 0; i < qtd; i++)
    {
        printf("\t");
    }
    printf("%c\n", node->item);
    print_tree(node->left, qtd + 1);
}

void free_node(t_node *node)
{
    if (node == NULL)
        return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

void clear_tree(t_tree *tree)
{
    free_node(tree->root);
    tree->number_of_chars = 0;
    tree->root = NULL;
}

void destroy_tree(t_tree *tree)
{
    free_node(tree->root);
    free(tree);
}