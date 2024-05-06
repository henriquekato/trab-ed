#include <stdlib.h>
#include "tree.h"

t_tree *create_tree(){
    t_tree *tree = (t_tree *) malloc(sizeof(t_tree));
    if (!tree) return NULL;
    tree -> root = NULL;
    return tree;
}

t_node *create_node(char item, int frequency){
    t_node *node = (t_node *) malloc(sizeof(t_node));
    node -> item = item;
    node -> frequency = frequency;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void calc(t_list *list)
{
    if (list->size < 2) return;
    t_node *smallest = list->items[0];
    t_node *second_smallest = list->items[1];
    int smallest_index = 0;
    int nd_smallest_index = 1;

    if (smallest->frequency < second_smallest->frequency)
    {
        int aux = smallest->frequency;
        smallest->frequency = second_smallest->frequency;
        second_smallest->frequency = aux;
    }

    for (int i = 2; i < list->size; i++)
    {
        if (list->items[i] != NULL && list->items[i]->frequency < smallest)
        {
            second_smallest = smallest;
            smallest = list->items[i];
            nd_smallest_index = smallest_index;
            smallest_index = i;
        }
        if (list->items[i] != NULL && list->items[i]->frequency < second_smallest)
        {
            second_smallest = list->items[i];
            nd_smallest_index = i;
        }
    }

    t_node *node = create_node('\0', smallest->frequency + second_smallest->frequency);
    list->items[smallest_index] = node;
    list->items[nd_smallest_index] = NULL;
}

// char *code(t_node *root, char *code){
//     if (root == NULL) return -1;
//     if (root == node) return 1;
//     int left = height(root -> left, node);
//     int right = height(root -> right, node);
//     if (left == -1 && right == -1) return 0;
//     if (left > right){
//         return strcpy("1");
//     }
//     if (right > left) {
//         return ++right;
//     }
//     return 0;
// }

// 1 + 100
// 1 + 00
// 0 + 0
// 0

// huffman_code *create_code_list(t_node *root, int number_of_chars){
//     huffman_code *code_list = (huffman_code *) malloc(number_of_chars * sizeof(huffman_code));

//     for (int i = 0; i < number_of_chars; i++){
//         code_list[i] -> code;  // tem q pegar a sequencia dele n sei como
//     }

// }
