typedef struct _node
{
    char item;
    int frequency;
    char *path;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct
{
    t_node **items;
    int size;
} t_list;

typedef struct
{
    t_node *root;
} t_tree;

typedef struct
{
    char letra;
    char *string;
} huffman_code;

t_list *create_list();
void append_item(t_list *list, char item, int frequency);
void remove_item(t_list *list, int index);
void print_list(t_list *list);

t_tree *create_tree();
t_node *create_node(char item, int frequency);
t_node *calc(t_list *list);
void node_path(t_node *node, char *path);
huffman_code *create_code(char *code, char letra);
void pre_order(t_node *node, int index, huffman_code **code_list);
huffman_code **create_code_list(t_node *root, int number_of_chars);
void print_tree(t_node *node, int qtd);
void print_pre_order(t_node *node);
void print_huffman(huffman_code **luiz, int number_of_chars);
void clear_tree(t_node *node);