typedef struct _node{
    char item;
    int frequency;
    char *path;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct{
    t_node **items;
    int size;
} t_list;

typedef struct{
    t_node *root;
} t_tree;

typedef struct{
    char letra;
    char *string;
} huffman_code;