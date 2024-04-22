#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

t_node *create_node(char c)
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->item = c;
    node->left = NULL;
    node->right = NULL;
    return node;
}

t_tree *create_root()
{
    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));
    tree->root = create_node('\0');
    return tree;
}


void print_pre_order(t_node *node)
{
    if (node == NULL) return;
    printf("%c ", node -> item);
    print_pre_order(node -> left);
    print_pre_order(node -> right);
}

void print_in_order(t_node *node) 
{
    if (node == NULL) return;
    print_in_order(node -> left); 
    printf("%c ", node -> item); 
    print_in_order(node -> right); 
}

void print_post_order(t_node *node)
{
    if (node == NULL) return;
    print_post_order(node -> left);
    print_post_order(node -> right);
    printf("%c ", node -> item);
}

    void create_tree(t_node *node, char *entrada)
{
    int i = 0;
    char item = ' ';
    while (entrada[i] != ',' && entrada[i] != ')')
    {
        if (entrada[i] != '(')
        {
            item = entrada[i];
        }
        i++;
    }
    if (item == ' ')
        return;
    node->item = item;

    int open = 0;
    int tamanho = 0;
    i++;
    int cp = i;
    do{
       if (entrada[i] == '(')
        {
            open++;
        } 
        if (entrada[i] == ')')
        {
            open--;
        }
        tamanho++;
        i++;
    }while (open != 0);
    if (node->left == NULL)
    {
        node->left = create_node('-');
    }
    char str1[100] = "";
    int x;
    for (x = cp; x < tamanho + cp; x++)
    {
        strncat(str1, &entrada[x], 1);
    }
    str1[x + 1] = '\0';
    create_tree(node->left, str1);

    i++;
    cp = i;
    tamanho = 0;
    do{
       if (entrada[i] == '(')
        {
            open++;
        } 
        if (entrada[i] == ')')
        {
            open--;
        }
        tamanho++;
        i++;
    }while (open != 0);
    if (node->right == NULL)
    {
        node->right = create_node('-');
    }
    char str2[100] = "";
    for (x = cp; x < tamanho + cp; x++)
    {
        strncat(str2, &entrada[x], 1);
    }
    str2[x + 1] = '\0';
    create_tree(node->right, str2);
}