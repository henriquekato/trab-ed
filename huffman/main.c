#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "tree.h"
// #include "list.h"
#include "types.h"

int main()
{
    char option[10] = "";
    t_tree *tree = create_tree();
    t_list *list = create_list();
    huffman_list *code_list = NULL;
    do
    {
        printf("->");
        scanf("%s", option);
        if (strcmp(option, "add") == 0)
        {
            char e;
            int frequency;
            scanf(" %c %d%*c", &e, &frequency);
            int index = if_char_in_list(list, e);
            if (index > -1)
            {
                list->items[index]->frequency = frequency;
            }
            else
            {
                append_item(list, e, frequency);
                if (tree->root != NULL)
                {
                    clear_tree(tree);
                }
                tree->number_of_chars++;
            }
            print_list(list);
        }
        else if (strcmp(option, "calc") == 0)
        {
            if (list->size < 2)
            {
                printf("\nInforme algum valor\n");
            }
            else
            {
                tree->root = calc(list);
                print_tree(tree->root, 0);
                clear_code_list(code_list);
                code_list = create_code_list(tree);
            }
        }
        else if (strcmp(option, "print") == 0)
        {
            print_huffman(code_list);
        }
        else if (strcmp(option, "cod") == 0)
        {
            char letters[100] = "";
            scanf(" %s", letters);
            cod(letters, code_list);
        }
        else if (strcmp(option, "dec") == 0)
        {
            char bits[100] = "";
            scanf(" %s", bits);
            dec(bits, code_list);
        }
        else if (strcmp(option, "clear") == 0)
        {
            clear_code_list(code_list);
            clear_list(list);
            clear_tree(tree);
        }
        printf("\n");
    } while (strcmp(option, "exit") != 0);
    destroy_code_list(code_list);
    destroy_list(list);
    destroy_tree(tree);
    return 0;
}
