#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list *create_list()
{
    t_list *list = (t_list *) malloc(sizeof(t_list));
    list->items = (t_node **) malloc(50 * sizeof(t_node *));
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
}