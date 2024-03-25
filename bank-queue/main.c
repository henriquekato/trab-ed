#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    t_queue *q_preferencial;
    t_queue *q_geral;

    q_preferencial = create_queue(10);
    q_geral = create_queue(10);

    get_input(q_preferencial, q_geral);
    return 0;
}
