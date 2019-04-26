/* binary_tree.h - Federico Cirett */ 
typedef char * Key;
typedef struct nodo Link;
typedef struct nodo {
    Key id;
    Link *l;
    Link *r;
} NODO;

void carga_datos(NODO **tree, int argc, char **argv);
void insert(NODO **tree, Key valor);
void print_preorder(NODO *tree);
void print_inorder(NODO *tree);
void print_postorder(NODO *tree);
void print_reverse_inorder(NODO *tree);
void display(NODO *tree);


void carga_datos(NODO **tree, int argc, char **argv) {
    int i;
    for(i = 1; i < argc; i++) {
        insert((tree), argv[i]);
    }
}

void insert(NODO **tree, Key valor) {
    NODO *tmp = NULL;
    if(*tree == NULL) {
        tmp = (NODO *) malloc(sizeof(NODO));
        tmp->id = strdup(valor);
        tmp->l  = NULL;
        tmp->r  = NULL;
        *tree   = tmp;
    } else {
        int ret;
    
        if(strcmp(valor, (*tree)->id) < 0) {
            insert(&(*tree)->l, valor);
        } else {
            if(strcmp(valor, (*tree)->id) > 0) {
                insert(&(*tree)->r, valor);
            }
        }
    }
    return;
}

void print_preorder(NODO *tree) {
    if(tree) {
        printf("%s ", tree->id);
        print_preorder(tree->l);
        print_preorder(tree->r);
    }
}

void print_reverse_inorder(NODO *tree) {
    if(tree) {
        print_reverse_inorder(tree->r);
        display(tree);
        print_reverse_inorder(tree->l);
    }
}

void print_inorder(NODO *tree) {
    if(tree) {
        print_inorder(tree->l);
        display(tree);
        print_inorder(tree->r);
    }
}

void print_postorder(NODO *tree) {
    if(tree) {
        print_postorder(tree->l); 
        print_postorder(tree->r);
        display(tree);
    }
}

void display(NODO *tree) {
    printf("%s\n", (char *) tree->id);
}