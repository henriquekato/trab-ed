#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "tree.h"
// #include "list.h"
#include "types.h"

int main()
{
    char option[10] = "";
    int number_of_chars = 0;
    t_list *list = create_list();
    t_tree *tree = create_tree();
    do
    {
        printf("->");
        scanf("%s", option);
        if (strcmp(option, "add") == 0)
        {
            char e;
            int frequency;
            scanf(" %c %d%*c", &e, &frequency);
            int index = if_char_in_list(list, number_of_chars, e);
            printf("index %d\n", index);
            if (index != -1)
            {
                list->items[index]->frequency = frequency;
                print_list(list); 
            }
            else
            {
                append_item(list, e, frequency);
                number_of_chars++;
                print_list(list); 
            }
        }
        else if (strcmp(option, "calc") == 0)
        {
            if (list -> size < 1){
                printf("\nInforme algum valor la\n");
            }
            else{
                tree -> root = calc(list);
                print_tree(tree -> root, 0);
            }
        }
        else if (strcmp(option, "print") == 0)
        {
            huffman_code ** luiz = create_code_list(tree->root, number_of_chars);
            print_huffman(luiz, number_of_chars);
        }
        else if (strcmp(option, "cod") == 0)
        {
            char text[10] = "";
            scanf(" %s", text);
        }
        else if (strcmp(option, "dec") == 0)
        {
            char bits[10] = "";
            scanf(" %s", bits);
        }
        else if (strcmp(option, "clear") == 0)
        {
            clear_tree(tree->root);
            number_of_chars = 0;
        }
        printf("\n");
    } while (strcmp(option, "exit") != 0);
    return 0;
}
