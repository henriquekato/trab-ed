#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

t_node *create_node()
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->item = '\0';
    node->left = NULL;
    node->right = NULL;
    return node;
}

t_tree *create_root()
{
    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));
    tree->root = create_node();
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

char *get_substring(char *input, t_node *node, int *i){
    int open = 0;
    int tamanho = 0;
    (*i)++;
    int cp = *i;
    do{
       if (input[*i] == '(')
        {
            open++;
        } 
        if (input[*i] == ')')
        {
            open--;
        }
        tamanho++;
        (*i)++;
    }while (open != 0);
    if (node->left == NULL)
    {
        node->left = create_node();
    }
    char *str = (char *) calloc(100, sizeof(char));
    int x;
    for (x = cp; x < tamanho + cp; x++)
    {
        strncat(str, &input[x], 1);
    }
    str[x + 1] = '\0';
    return str;
}

void create_tree(t_node *node, char *input)
{
    int i = 0;
    char item = '\0';
    while (input[i] != ',' && input[i] != ')')
    {
        if (input[i] != '(')
        {
            item = input[i];
        }
        i++;
    }
    if (item == '\0')
        return;
    node->item = item;

    char *str1 = get_substring(input, node, &i);
    create_tree(node->left, str1);
    free(str1);

    char *str2 = get_substring(input, node, &i);
    create_tree(node->right, str2);
    free(str2);
}

int height(t_node *root){
    if (root == NULL) return -1;
    int left = height(root -> left);
    int right = height(root -> right);
    if (left > right){
        return ++left;
    }
    else{
        return ++right;
    }
}