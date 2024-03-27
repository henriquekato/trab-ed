#include <stdio.h>
#include <stdlib.h>
#include "t_stack.h"

/*
    Estratégia faz sentido: 
    Foi implementada: 
*/

int main()
{
    int n;
    printf("Informe o número de elementos:");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    non_recursive_qsort(array, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
