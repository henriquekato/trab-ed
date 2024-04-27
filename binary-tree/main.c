#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// valid tree: (A,(B,(),()),(C,(F,(),()),()))
// valid tree: (A,(B,(),()),(C,(F,(),()),(T,(),())))
// valid tree: (A,(B,(),()),(C,(F,(),()),(T,(J,(),()),())))
// valid tree: (D,(B,(A,(),()),(C,(),())),(F,(E,(),()),(G,(),())))
// invalid tree: (A,(B,()),(C,(F,(),()),()))

int main()
{
    char input[100];
    int option;
    t_binary_tree *tree = create_tree();
    do
    {
        printf("[0] - create tree\n");
        printf("[1] - pre-order\n");
        printf("[2] - in-order\n");
        printf("[3] - post-order\n");
        printf("[4] - height\n");
        printf("[5] - print tree\n");
        printf("[6] - exit\n");
        scanf("%d%*c", &option);
        if (option == 0)
        {
            gets(input);
            if (is_valid(input)){
                if (tree -> root -> left != NULL || tree -> root -> right != NULL){
                    clear_tree(tree -> root);
                    tree = create_tree();
                }
                fill_tree(tree->root, input);
            }
            else{
                printf("\ninput invalido\n");
            }
        }
        if (option == 1)
        {
            print_pre_order(tree->root);
            printf("\n");
        }
        if (option == 2)
        {
            print_in_order(tree->root);
            printf("\n");
        }
        if (option == 3)
        {
            print_post_order(tree->root);
            printf("\n");
        }
        if (option == 4)
        {
            printf("height: %d\n", height(tree -> root));
        }
        if (option == 5)
        {
            print_tree(tree -> root, 0);
        }
    }while(option != 6);
    return 0;
}
