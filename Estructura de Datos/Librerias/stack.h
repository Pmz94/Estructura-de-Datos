typedef struct elemento{
    int valor;
    struct elemento *sig; /* siguiente nodo */
}NODO;

NODO * nuevo_nodo( void ){
    struct elemento *p;
    p = (NODO *) malloc( sizeof( NODO ) );
    p->valor= 0;
    p->sig = NULL;
    return p;
}

void push(NODO **head, int valor){
    NODO *nodo;
    nodo = nuevo_nodo();
    if(*head == NULL){
        nodo->valor = valor;
        nodo->sig   = NULL;
        //printf(">>>nodo:%u valor:%d sig:%u\n",nodo, nodo->valor, nodo->sig);
        *head = nodo;
    }else{
        nodo->valor = valor;
        nodo->sig = *head;
        *head = nodo;
       //printf(">>>HEAD:%u head->sig:%u valor:%d\n", *head, *head->sig, *head->valor);
    }
}

int pop(NODO **head){
    int valor=-1;
    if (head!= NULL){
        NODO *tmp;
        tmp = *head;
        valor = tmp->valor;
        *head = tmp->sig;
        free(tmp);
    }
    return(valor);
}

void display_stack( NODO *p ){
    while ( p !=NULL ){
        printf("valor:%d \n",p->valor);
        p = p->sig;
    }
}