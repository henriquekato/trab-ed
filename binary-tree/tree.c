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

t_binary_tree *create_tree()
{
    t_binary_tree *tree = (t_binary_tree *)malloc(sizeof(t_binary_tree));
    tree->root = create_node();
    return tree;
}


void print_pre_order(t_node *node)
{
    if (node == NULL || node -> item == '\0') return;
    printf("%c ", node -> item);
    print_pre_order(node -> left);
    print_pre_order(node -> right);
}

void print_in_order(t_node *node) 
{
    if (node == NULL || node -> item == '\0') return;
    print_in_order(node -> left); 
    printf("%c ", node -> item); 
    print_in_order(node -> right); 
}

void print_tree(t_node *node, int qtd) 
{   
    if (node == NULL || node -> item == '\0') return;
    print_tree(node -> right, qtd + 1); 
    for (int i = 0; i < qtd; i++){
        printf("\t");
    }
    printf("%c\n", node -> item); 
    print_tree(node -> left, qtd + 1); 
}

void print_post_order(t_node *node)
{
    if (node == NULL || node -> item == '\0') return;
    print_post_order(node -> left);
    print_post_order(node -> right);
    printf("%c ", node -> item);
}

int get_string_size(char *string, int *i){
    int opened = 0;
    int size = 0;
    do{
       if (string[*i] == '(')
        {
            opened++;
        } 
        if (string[*i] == ')')
        {
            opened--;
        }
        size++;
        (*i)++;
    }while (opened != 0);
    return size;
}

char *get_substring(char *input, int start_index, int size){
    char *str = (char *) calloc(100, sizeof(char));
    int x;
    for (x = start_index; x < size + start_index; x++)
    {
        strncat(str, &input[x], 1);
    }
    str[x + 1] = '\0';
    return str;
}

int is_valid(char *input){
    int letters = 0, opened = 0, closed = 0;
    int i = 0;
    while (i < (int) strlen(input))
    {
        if (input[i] != '\0' && input[i] != ' ' && input[i] != '(' && input[i] != ')' && input[i] != ',')
        {
            letters++;
        }
        if (input[i] == '(')
        {
            opened++;
        }
        else if (input[i] == ')')
        {
            closed++;
        }
        i++;
    }

    if (opened != closed) return 0;
    if ((letters * 2) + 1 == opened && (letters * 2) + 1 == closed)
    {
        return 1;
    }
    return 0;
}

void fill_tree(t_node *node, char *input)
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

    int size;
    int start_index = ++i;
    size = get_string_size(input, &i);
    if (node->left == NULL)
    {
        node->left = create_node();
    }

    char *str1 = get_substring(input, start_index, size);
    fill_tree(node->left, str1);
    free(str1);

    start_index = ++i;
    size = get_string_size(input, &i);
    if (node->right == NULL)
    {
        node->right = create_node();
    }

    char *str2 = get_substring(input, start_index, size);
    fill_tree(node->right, str2);
    free(str2);
}

t_node *get_node_by_item(t_node *root, char item){
    if (root == NULL) return NULL; 
    
    if (root -> item == item) return root;

    t_node *left = get_node_by_item(root -> left, item);
    if (left != NULL) return left;
    
    return get_node_by_item(root -> right, item);
}

int height(t_node *root, t_node *node){
    if (root == NULL) return -1;
    if (root == node) return 1;
    int left = height(root -> left, node);
    int right = height(root -> right, node);
    if (left == -1 && right == -1) return 0;
    if (left > right){
        return ++left;
    }
    if (right > left) {
        return ++right;
    }
    return 0;
}

void clear_tree(t_node *node){
    if (node == NULL) return;
    clear_tree(node -> left); 
    clear_tree(node -> right); 
    free(node);
}