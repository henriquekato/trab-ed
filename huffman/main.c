#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "list.h"

int main()
{
    char option[10] = "";
    int number_of_chars = 0;
    t_list *list = create_list();
    do
    {
        scanf("%s", option);
        if (strcmp(option, "add") == 0)
        {
            char e;//characteresrs
            int frequency;
            scanf(" %c %d%*c", &e, &frequency);
            // if ()//(e not in list)
            // {
                append_item(list, e, frequency);
                number_of_chars++;
            // }
            // else
            // {

            // }
        }
        else if (strcmp(option, "calc") == 0)
        {
        }
        else if (strcmp(option, "print") == 0)
        {
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
            number_of_chars = 0;
        }
    } while (!strcmp(option, "exit"));
    return 0;
}
