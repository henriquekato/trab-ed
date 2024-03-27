#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

t_queue *create_queue(int n)
{
    t_queue *q = (t_queue *)malloc(sizeof(t_queue));
    if (!q)
    {
        exit(1);
    }
    q->max = n;
    q->start = 0;
    q->end = 0;
    q->n = 0;
    q->items = (char **)malloc(sizeof(char *) * n);
    if (!q->items)
    {
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        q->items[i] = (char *)malloc(sizeof(char) * 50);
        if (!q->items[i])
        {
            exit(1);
        }
    }
    return q;
}

int realloc_queue(t_queue *q)
{
    char **new = (char **)realloc(q->items, (q->max + 5) * sizeof(char *));
    if (!new)
    {
        exit(1);
    }

    q->items = new;

    for (int i = q->max; i < q->max + 5; i++)
    {
        q->items[i] = (char *)malloc(50 * sizeof(char));
        if (!q->items[i])
        {
            exit(1);
        }
    }
    if (q->end == 0)
    {
        q->end = q->max;
    }
    q->max += 5;
    return 1;
}

void destroy(t_queue *q)
{
    free(q->items);
    free(q);
}

int move_right(t_queue *q)
{
    for (int i = 0; i <= q->end; i++)
    {
        strcpy(q->items[(q->n + i) % q->max], q->items[i]);
    }
    q->end = (q->n + q->end) % q->max;
    return 1;
}

int in(t_queue *q, char *x)
{
    if (is_full(q))
    {
        realloc_queue(q);
        if (q->start > 0)
        {
            move_right(q);
        }
    }
    strcpy(q->items[q->end], x);
    q->end = (q->end + 1) % q->max;
    q->n++;
    return 1;
}

int out(t_queue *q, char *x)
{
    if (is_empty(q))
    {
        return 0;
    }
    strcpy(x, q->items[q->start]);
    q->start = (q->start + 1) % q->max;
    q->n--;
    return 1;
}

int is_full(t_queue *q)
{
    if (q->n == q->max)
    {
        return 1;
    }
    return 0;
}

int is_empty(t_queue *q)
{
    if (q->n == 0)
    {
        return 1;
    }
    return 0;
}

int size(t_queue *q)
{
    return q->n;
}

void clear(t_queue *q)
{
    q->start = 0;
    q->end = 0;
    q->n = 0;
}

void print_queue(t_queue *q)
{
    for (int i = q->start; i < q->start + q->n; i++)
    {
        printf("%s\n", q->items[i % q->max]);
    }
    printf("\n");
}

void print_output(char **ordem_atendimento, int qtd_atendido){
    for (int i = 0; i < qtd_atendido; i++)
    {
        printf("%s\n", ordem_atendimento[i]);
    }
}

void get_input(t_queue *q_preferencial, t_queue *q_geral)
{
    char **ordem_atendimento = (char **)malloc(sizeof(char *) * 50);
    if (!ordem_atendimento)
    {
        exit(1);
    }
    for (int i = 0; i < 50; i++)
    {
        ordem_atendimento[i] = (char *)malloc(sizeof(char) * 50);
        if (!ordem_atendimento[i])
        {
            exit(1);
        }
    }
    int preferencial_seguidos = 0, qtd_atendido = 0;

    char tipo;
    char nome[50];
    do
    {
        scanf(" %c", &tipo);
        switch (tipo)
        {
        case 'g':
            scanf(" %s", nome);
            in(q_geral, nome);
            break;
        case 'p':
            scanf(" %s", nome);
            in(q_preferencial, nome);
            break;
        case 's':
            if ((preferencial_seguidos < 3 && !is_empty(q_preferencial)) || is_empty(q_geral))
            {
                out(q_preferencial, ordem_atendimento[qtd_atendido]);
                preferencial_seguidos++;
            }
            else
            {
                out(q_geral, ordem_atendimento[qtd_atendido]);
                preferencial_seguidos = 0;
            }
            qtd_atendido++;
            break;
        }
    } while (tipo != 'f');

    print_output(ordem_atendimento, qtd_atendido);
    for (int i = 0; i < qtd_atendido; i++){
        free(ordem_atendimento[i]);
    }
    free(ordem_atendimento);
}
