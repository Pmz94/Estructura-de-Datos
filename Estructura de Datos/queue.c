/* Autor Pedro Muñoz
Fecha: 22 de Septiembre de 2015
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
	int valor;
	struct elemento * sig;
}NODO;

typedef struct queue{
	NODO * head;
	NODO * tail;
	int cuenta;
}QUEUE;

void put(QUEUE * q, int v);
QUEUE * initializeQueue(void);
NODO * nuevo_nodo(void);
int get(QUEUE * cola);
void insert (int size, char ** array, QUEUE **q);
void display (QUEUE *cola);

int main (int argc, char **argv){
	QUEUE * cola=NULL;
	cola = initializeQueue();
	insert (argc, argv, &cola);
	display(cola);
	int x = get(cola);
	printf("x=%d\n",x);
	display(cola);
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

QUEUE * initializeQueue(void){
QUEUE * Q = NULL;
Q = (QUEUE*)malloc(sizeof(QUEUE));
Q->head=NULL;
Q->tail=NULL;
Q->cuenta=0;
return Q;
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