typedef int t_elem;

typedef struct
{
    int max;
    int index_top;
    t_elem *items;
} t_stack;

t_stack *create_stack(int n);
int realloc_stack(t_stack *p);
void destroy(t_stack *p);
int push(t_stack *p, int x);
int pop(t_stack *p, int *x);
int is_full(t_stack *p);
int is_empty(t_stack *p);
void swap(int *posA, int *posB);
int partition(int array[], int start, int end);
void non_recursive_qsort(int array[], int start, int end);