typedef struct _node
{
    char item;
    char *path;
    int frequency;
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
    int number_of_chars;
} t_tree;

typedef struct
{
    char item;
    char *code;
    int frequency;
} huffman_code;

typedef struct
{
    huffman_code **items;
    int size;
} huffman_list;

t_list *create_list();
void append_item(t_list *list, char item, int frequency);
void remove_item(t_list *list, int index);
void print_list(t_list *list);
int if_char_in_list(t_list *list, char e);
void clear_list(t_list *list);
void destroy_list(t_list *list);

t_tree *create_tree();
t_node *create_node(char item, int frequency);
t_node *calc(t_list *list);
void print_tree(t_node *node, int qtd);
void free_node(t_node *node);
void clear_tree(t_tree *tree);
void destroy_tree(t_tree *tree);

void node_path(t_node *node, char *path);
huffman_code *create_code(t_node *node);
void pre_order(t_node *node, huffman_list *code_list);
huffman_list *create_huffman_list(t_tree *tree);
huffman_list *create_code_list(t_tree *tree);
void print_huffman(huffman_list *code_list);
void clear_code_list(huffman_list *code_list);
void destroy_code_list(huffman_list *code_list);
void dec(char *sequence, huffman_list *code_list);
void cod(char *sequence, huffman_list *code_list);
