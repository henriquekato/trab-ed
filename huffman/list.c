#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

t_list *create_list()
{
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->items = (t_node **)malloc(50 * sizeof(t_node *));
    list->size = 0;
    return list;
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