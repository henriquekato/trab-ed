#ifndef LIST_H
#define LIST_H

#include "types.h"

t_node *create_node(char item, int frequency);
t_list *create_list();
void append_item(t_list *list, char item, int frequency);
void remove_item(t_list *list, int index);
void print_list(t_list *list);
int if_char_in_list(t_list *list, char e);
void clear_list(t_list *list);
void destroy_list(t_list *list);
t_node *calc(t_list *list);

#endif // LIST_H