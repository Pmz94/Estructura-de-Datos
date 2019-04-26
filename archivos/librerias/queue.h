/* =============== QUEUE ============ */
typedef struct elemento {
    int valor;
    struct elemento *sig; /* siguiente nodo */
} NODO;

typedef struct Queue {
    NODO *head;
    NODO *tail;    
    int   size;
} QUEUE;

void put(QUEUE *cola, int valor);
int get(QUEUE *cola);
void display_queue(QUEUE *cola);
QUEUE * createQueue(void);
NODO * nuevo_nodo(void);

/* =============== QUEUE ============ */
NODO * nuevo_nodo(void) {
    struct elemento *p;
    
    p = (NODO *) malloc(sizeof(NODO));
    
    p->valor = 0;
    p->sig = NULL;
    
    return p;
}

void put(QUEUE *cola, int valor) {
    NODO* n = nuevo_nodo();
    n->valor = valor;

    if(cola->head == NULL) { // si la cola esta vacia
        cola->head = n;
    } else {
        cola->tail->sig = n;
    }
    cola->tail = n;
    cola->size++;
}

int get(QUEUE* cola) {
    // toma el primer nodo
    NODO* head = cola->head;
    int valor = head->valor;
    // mueve el apuntador de la cabeza al siguiente nodo
    // y disminuye el tamano de la cola
    cola->head = head->sig;
    cola->size--;
    // libera la memoria de 'head' original
    free(head);
    return valor;
}

void display_queue(QUEUE* cola) {
    printf("\nDisplay: ");
    // no item
    if(cola->size == 0)
        printf("La cola esta vacia.\n");
    else { // has item(s)
        NODO* head = cola->head;
        int i; 
        int size = cola->size;
        printf("%d nodo(s):\n", cola->size);
        for(i = 0; i < size; i++) {
            if(i > 0) printf(", ");
            printf("%d", head->valor);
            head = head->sig;
        }
    }
    printf("\n");
}

QUEUE * createQueue() {
    QUEUE *queue;
    
    queue = (QUEUE *) malloc(sizeof(QUEUE));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}