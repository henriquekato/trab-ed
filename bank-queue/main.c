#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    t_queue *q_preferencial;
    t_queue *q_geral;

    q_preferencial = create_queue(3);
    q_geral = create_queue(3);

    get_input(q_preferencial, q_geral);
    return 0;
}

/*
g Rodrigo
g Bia
p Joel
s
g Fatima
p Frederico
p Luciana
s
s
p Fabiana
p Elen
p Fabio
g Valter
s
s
s
s
s
s
s
f
-----------------------------------------
g Rodrigo
g Bia
p Joel
g Fatima
p Frederico
p Luciana
p Fabiana
p Elen
p Fabio
g Valter
p Fabiana2
p Elen2
p Fabio2
g Valter2
s
s
s
s
s
s
s
s
s
s
s
s
s
s
f
-----------------------------------------
p Luana
p Joaquim
g Manoel
s
s
p Caio
p Nair
g Gustavo
s
s
s
s
f
*/