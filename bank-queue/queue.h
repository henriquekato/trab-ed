typedef struct
{
    int max;
    int start;
    int end;
    int n;
    char **items;
} t_queue;

t_queue *create_queue(int n);
int realloc_queue(t_queue *p);
void destroy(t_queue *p);
void get_input(t_queue *q_preferencial, t_queue *q_geral);
int in(t_queue *p, char *x);
int out(t_queue *p, char *x);
void print_output(char **ordem_atendimento, int qtd_atendido);
int move_left(t_queue *q);
int move_right(t_queue *q);
int is_full(t_queue *p);
int is_empty(t_queue *p);
int is_empty(t_queue *p);
int size(t_queue *p);
void clear(t_queue *p);
void print_queue(t_queue *p);