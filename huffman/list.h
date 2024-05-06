// typedef struct _node
// {
//     char item;
//     int frequency;
//     struct _node *left;
//     struct _node *right;
// } t_node;

// typedef struct
// {
//     t_node **items;
//     int size;
// } t_list;
#include "types.h"
t_list *create_list();
void append_item(t_list *list, char item, int frequency);
void remove_item(t_list *list, int index);
void print_list(t_list *list);