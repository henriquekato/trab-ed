#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// tree
t_tree *create_tree()
{
    t_tree *tree = (t_tree *)malloc(sizeof(t_tree));
    if (!tree)
        return NULL;
    tree->root = NULL;
    return tree;
}

t_node *create_node(char item, int frequency)
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->item = item;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    node->path = "";
    node->path = (char *)malloc(100 * sizeof(char));
    return node;
}

// list
t_list *create_list()
{
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->items = (t_node **)malloc(50 * sizeof(t_node *));
    list->size = 0;
    return list;
}

void append_item(t_list *list, char item, int frequency)
{
    list->items[list->size++] = create_node(item, frequency);
}

void remove_item(t_list *list, int index)
{
    if (list->size > 0)
    {
        list->items[index] = list->items[--list->size];
    }
}

void print_list(t_list *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%c%d ", list->items[i]->item, list->items[i]->frequency);
    }
    printf("\n");
}

int if_char_in_list(t_list *list, int number_of_chars, char e)
{
    for (int i = 0; i < number_of_chars; i++)
    {
        if (list->items[i]->item == e)
        {
            return i;
        }
    }
    return -1;
}

// tree
//  すごい
//  geral: retorna a arvore (nó raiz) -> atribuido a tree->root no main
//  1: pega os dois menor freq (maximo duas vezes: dois nó q é so nó)
//  ou 1 nó de vdd + nó de mentira
// 2: cria o nó de mentira, left e right
// 3: att a lista

t_node *calc(t_list *list)
{
    if (list->size < 2)
        return list->items[0];

    int max_size = list->size;
    for (int i = 0; i < max_size; i++)
    {
        // dois menor
        t_node *smallest_st = list->items[0];
        int i_smallest_st = 0;
        t_node *smallest_nd = list->items[1];
        int i_smallest_nd = 1;
        for (int j = 0; j < list->size; j++)
        {
            if (list->items[j]->frequency < smallest_st->frequency)
            {
                smallest_nd = smallest_st;
                i_smallest_nd = i_smallest_st;
                smallest_st = list->items[j];
                i_smallest_st = j;
            }
            else if (list->items[j]->frequency < smallest_nd->frequency && i_smallest_st != j)
            {
                smallest_nd = list->items[j];
                i_smallest_nd = j;
            }
        }
        list->items[i_smallest_nd] = create_node('-', smallest_nd->frequency + smallest_st->frequency);
        list->items[i_smallest_nd]->left = smallest_nd;
        list->items[i_smallest_nd]->right = smallest_st;
        remove_item(list, i_smallest_st);
    }
    t_node *root = list->items[0];
    remove_item(list, 0);
    return root;
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

void print_pre_order(t_node *node)
{
    if (node == NULL)
        return;
    printf("%c ", node->item);
    print_pre_order(node->left);
    print_pre_order(node->right);
}

void node_path(t_node *node, char *path)
{
    if (node == NULL)
        return;

    strcpy(node->path, path);

    char left_path[100], right_path[100];
    strcpy(left_path, path);
    strcat(left_path, "1");
    node_path(node->left, left_path);

    strcpy(right_path, path);
    strcat(right_path, "0");
    node_path(node->right, right_path);
}

huffman_code *create_code(t_node *node)
{
    huffman_code *huff_code = (huffman_code *)malloc(sizeof(huffman_code));
    huff_code->string = (char *)malloc(100 * sizeof(char));

    strcpy(huff_code->string, node -> path);
    huff_code->letra = node -> item;
    huff_code->frequency = node -> frequency;
    return huff_code;
}

void pre_order(t_node *node, int *index, huffman_code **code_list)
{
    if (node == NULL || node->item == '\0')
        return;
    if (node->item != '-')
    {
        code_list[(*index)++] = create_code(node);
    }
    pre_order(node->left, index, code_list);
    pre_order(node->right, index, code_list);
}

huffman_code **create_code_list(t_node *root, int number_of_chars)
{
    huffman_code **code_list = (huffman_code **)malloc(number_of_chars * sizeof(huffman_code *));

    int index = 0;

    node_path(root, "");
    pre_order(root, &index, code_list);

    return code_list;
}

void print_huffman(huffman_code **code_list, int number_of_chars)
{
    for (int i = 0; i < number_of_chars; i++)
    {
        printf("%c com frequencia %d codificado como %s\n", code_list[i]->letra, 
                                                            code_list[i]->frequency,
                                                            code_list[i]->string);
    }
}

void clear_tree(t_node *node)
{
    if (node == NULL)
        return;
    clear_tree(node->left);
    clear_tree(node->right);
    free(node);
}
