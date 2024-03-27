#include <stdio.h>
#include <stdlib.h>
#include "t_stack.h"

t_stack *create_stack(int n)
{
    t_stack *p = (t_stack *)malloc(sizeof(t_stack));
    if (!p)
    {
        exit(0);
    }
    p->max = n;
    p->index_top = -1;
    p->items = (t_elem *)malloc(sizeof(t_elem) * n);
    if (!p->items)
    {
        exit(0);
    }
    return p;
}

int realloc_queue(t_stack *p)
{
    p->items = (t_elem *)realloc(p->items, (p->max + 5) * sizeof(t_elem));
    if (!p->items)
    {
        exit(1);
    }
    p->max += 5;
    return 1;
}

void destroy(t_stack *p)
{
    free(p->items);
    free(p);
}

int push(t_stack *p, int x)
{
    if (is_full(p))
    {
        realloc_queue(p);
    }
    p->items[++p->index_top] = x;
    return 1;
}

int pop(t_stack *p, int *x)
{
    if (is_empty(p))
    {
        return 0;
    }
    *x = p->items[p->index_top--];
    return 1;
}

int is_full(t_stack *p)
{
    if (p->index_top + 1 == p->max)
    {
        return 1;
    }
    return 0;
}

int is_empty(t_stack *p)
{
    if (p->index_top < 0)
    {
        return 1;
    }
    return 0;
}

void swap(int *posA, int *posB)
{
    int aux = *posA;
    *posA = *posB;
    *posB = aux;
}

int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[end]);
    return i + 1;
}

void non_recursive_qsort(int array[], int start, int end)
{
    t_stack *p = create_stack(4);
    push(p, start);
    push(p, end);

    while (!is_empty(p))
    {
        pop(p, &end);
        pop(p, &start);
        
        int posPivot = partition(array, start, end);
        if (posPivot - 1 > start)
        {
            push(p, start);
            push(p, posPivot - 1);
        }

        if (posPivot + 1 < end)
        {
            push(p, posPivot + 1);
            push(p, end);
        }
    }
    destroy(p);
}
