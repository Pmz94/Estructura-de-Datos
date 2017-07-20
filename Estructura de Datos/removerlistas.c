/* Autor Pedro Muñoz
Fecha: 22 de Septiembre de 2015
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct elemento{
	int valor;
	struct elemento * sig;
}NODO;

typedef struct queue{
	NODO * head;
	NODO * tail;
	int cuenta;
}QUEUE;

QUEUE * initializeQueue(void);
void put(QUEUE * q, int v);
NODO * nuevo_nodo(void);
int get(QUEUE * cola);
void insert (int size, char ** array, QUEUE **q);
void display (QUEUE *cola);
void inserta_valores(QUEUE **Q, int maximo);
void remover_de_lista(QUEUE **cola, int size, char **array);
int remove_item(QUEUE * cola, int numero);

int main (int argc, char **argv){
	QUEUE * cola=NULL;
	cola = initializeQueue();
	if(argc>=2){
		inserta_valores(&cola, atoi(argv[1]));
		if(argc>=3){
			display(cola);
			remover_de_lista(&cola, argc, argv);
			display(cola);
		}else{
			display(cola);
		}
	}else{
		printf("se debe agregar al menos un numero a los argumentos\n");
	}
	return 0;
}

void inserta_valores(QUEUE **Q, int maximo){
	if(maximo>0){
		for(int i=0; i<=maximo; i++){
			put(*Q,i);
		}
	}
}

void remover_de_lista(QUEUE **cola, int size, char **array){
	for(int i=2; i<size; i++){
		remove_item(*cola, atoi(array[i]));
	}
}

int remove_item(QUEUE * cola, int numero){
	int x = -1;
	if(cola->cuenta>0){
		
		NODO * p = cola ->head;
		NODO * ant = cola->head;
		x=p->valor;
		if(x==numero){
			cola->head=cola->head->sig;
			cola->cuenta = cola->cuenta -1;
			free (p);
		}else{
			while(p!=NULL){
				if(p->valor== numero){
					ant->sig = p->sig;
					x=p->valor;
					free(p);
					p=ant->sig;
				}else{
					ant=p;
					p=p->sig;
				}
			}
		}
	}return x;
}

QUEUE * initializeQueue(void){
	QUEUE * Q = NULL;
	Q = (QUEUE*)malloc(sizeof(QUEUE));
	Q->head=NULL;
	Q->tail=NULL;
	Q->cuenta=0;
	return Q;
}

void put(QUEUE * Q, int v){
	NODO * p = nuevo_nodo();
	p->valor = v;
		if(Q->head==NULL){
			Q->head=p;
		}else{
			Q->tail->sig=p;
		}
		Q->tail=p;
		Q->cuenta++;
}

NODO * nuevo_nodo(void){
	NODO * ptr= NULL;
	ptr = (NODO *)malloc(sizeof(NODO));
	if(ptr == NULL){
		return NULL;
	}else{
		ptr->valor=0;
		ptr->sig=NULL;
		return ptr;
		}
	}

int get(QUEUE * cola){
	int x = -1;
	if(cola->cuenta >0){
		
		NODO * p = cola ->head;
		x=p->valor;
		cola->head=cola->head->sig;
		cola->cuenta = cola->cuenta -1;
		free (p);
		
	}return x;
}

void insert (int size, char ** array, QUEUE **q){
	int temp;
	int i;
	for(int i=0; i<size; i++){
		if(isdigit(*array[i])){
			temp=atoi(array[i]);
			put(*q,temp);
		}
	}
}

void display (QUEUE *cola){
	if(cola->cuenta==0){
		printf("la cola se encuentra vacia\n");
	}else{
		NODO *ptr=cola->head;
		while(ptr!=NULL){
			printf("%d:",ptr->valor);
			ptr=ptr->sig;
		}
		
		printf("\n");
	}
}