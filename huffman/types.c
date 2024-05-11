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
    tree->number_of_chars = 0;
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

int if_char_in_list(t_list *list, char e)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->items[i]->item == e)
        {
            return i;
        }
    }
    return -1;
}

void clear_list(t_list *list)
{
    if (list->size > 0)
    {
        for (int i = 0; i < list->size; i++)
        {
            free(list->items[i]);
        }
        list->size = 0;
    }
}

void destroy_list(t_list *list)
{
    clear_list(list);
    free(list->items);
    free(list);
}

t_node *calc(t_list *list)
{
    int max_size = list->size;
    for (int i = 0; i < max_size; i++)
    {
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

// huffman code
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
    huff_code->code = (char *)malloc(100 * sizeof(char));

    strcpy(huff_code->code, node->path);
    huff_code->item = node->item;
    huff_code->frequency = node->frequency;
    return huff_code;
}

void pre_order(t_node *node, huffman_list *code_list)
{
    if (node == NULL)
        return;
    if (node->item != '-')
    {
        code_list->items[code_list->size++] = create_code(node);
    }
    pre_order(node->left, code_list);
    pre_order(node->right, code_list);
}

huffman_list *create_huffman_list(t_tree *tree)
{
    huffman_list *list = (huffman_list *)malloc(sizeof(huffman_list));
    list->items = (huffman_code **)malloc(tree->number_of_chars * sizeof(huffman_code *));
    list->size = 0;
    return list;
}

huffman_list *create_code_list(t_tree *tree)
{
    huffman_list *code_list = create_huffman_list(tree);

    node_path(tree->root, "");
    pre_order(tree->root, code_list);

    return code_list;
}

void print_huffman(huffman_list *code_list)
{
    if (code_list == NULL) return;
    for (int i = 0; i < code_list->size; i++)
    {
        printf("%c com frequencia %d codificado como %s\n",
               code_list->items[i]->item,
               code_list->items[i]->frequency,
               code_list->items[i]->code);
    }
}

void clear_code_list(huffman_list *code_list)
{
    if (code_list != NULL && code_list->size > 0)
    {
        for (int i = 0; i < code_list->size; i++)
        {
            free(code_list->items[i]->code);
            free(code_list->items[i]);
        }
        code_list->size = 0;
    }
}

void destroy_code_list(huffman_list *code_list)
{
    clear_code_list(code_list);
    free(code_list);
}

// tree
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

void dec(char *sequence, huffman_list *code_list){
    char *result = (char *) calloc(100, sizeof(char));
    char *bits = (char *) calloc(10, sizeof(char));

    for (int i = 0; i < (int) strlen(sequence); i++){
        strncat(bits, &sequence[i], 1);
        for (int j = 0; j < code_list -> size; j++){
            if (strcmp(bits, code_list -> items[j] -> code) == 0){
                strncat(result, &code_list -> items[j] -> item, 1);
                strcpy(bits, "");
            }
        }
    }
    printf("%s\n", result);
    free(result);
    free(bits);
}

void cod(char *sequence, huffman_list *code_list){
    char *result = (char *) calloc(100, sizeof(char));
    int letter_unique = code_list -> size;

    int sequence_size = strlen(sequence) * 8;
    int result_size;

    for (int i = 0; i < (int) strlen(sequence); i++){
        for (int j = 0; j < code_list -> size; j++){
            if (sequence[i] == code_list -> items[j] -> item){
                strcat(result, code_list -> items[j] -> code);
            }
        }
    }

    result_size = strlen(result);
    float max_bit = (float) result_size/sequence_size;
    float min_bit = (float) sequence_size/letter_unique;
    
    printf("%s %.2f%% %.2f%%\n", result, max_bit * 100,
                                (result_size/min_bit) * 100);
    free(result);
}