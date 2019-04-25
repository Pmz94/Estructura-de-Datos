/* Autor Pedro Muñoz
Fecha: 5 de Octubre de 2015
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define HEAD 0
#define TAIL 1

typedef struct elemento{
	int valor;
	struct elemento * ant;
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
void display (QUEUE *cola, int orden);
void inserta_argumentos(QUEUE **q, int size, char **array);
void inserta_valores(QUEUE *Q, int valor);

int main (int argc, char **argv){
	QUEUE * cola=NULL;
	cola = initializeQueue();
	inserta_argumentos(&cola, argc, argv);
	display(cola, HEAD);
}

QUEUE * initializeQueue(void){
	QUEUE * Q = NULL;
	Q = (QUEUE *)malloc(sizeof (QUEUE));
	Q->head = NULL;
	Q->tail=NULL;
	Q->cuenta=0;
	return Q;
}

void inserta_argumentos(QUEUE **q, int size, char **array){
	int i;
	int temp;
	for(int i=1; i<size; i++){
		if(isdigit(*array[i])){
			temp=atoi(array[i]);
			inserta_valores(*q, temp);
		}
	}
}

void inserta_valores(QUEUE *Q, int valor){
	NODO *p=nuevo_nodo();
	p->valor = valor;
	if(Q->head == NULL){
		Q->head = p;
	}else{
		NODO *tmp = Q->head;
		if(tmp->valor > p->valor){	//si la cabeza es mayor
			tmp->ant = p;			//el anterior es el nuevo valor
			p->sig = tmp;			//el sig del nuevo valor es la cabeza
			Q->head = p;			//la cabeza ahora es el nuevo valor
		}else{
			NODO *anterior = Q->head;
			while(tmp!=NULL){
				if(tmp->valor > p->valor){
					anterior->sig = p;
					p->sig = tmp;
					tmp->ant = p;
				}
				anterior = tmp;
				tmp = tmp->sig;
			}
		}
	}
	Q->cuenta++;
}

void insert(int size, char **array, QUEUE ** Q){
	int temp;
	int i;
	for( i=0; i<size; i++){
		if(isdigit(*array[i])){
			temp = atoi(array[i]);
			put(*Q, temp);
		}
	}
} 

void put(QUEUE * Q , int v){
	NODO * p = nuevo_nodo();
	p->valor = v;
	if(Q->head == NULL){
		Q->head = p;
	}else{
		Q->tail -> sig = p;
		p->ant = Q->tail;
	}
	Q->tail = p;
	Q->cuenta++; 
}

NODO * nuevo_nodo (void){
	NODO * ptr=NULL;
	ptr=(NODO *)malloc(sizeof(NODO));
		if(ptr==NULL){
			return NULL;
		}else{
			ptr->valor=0;
			ptr->ant=NULL;
			ptr->sig = NULL;
		return ptr;
		}
}

int get (QUEUE * cola){
	int x = -1;
	if(cola->cuenta>0){
		NODO * cabeza = cola->head;
		cola->head = cabeza->sig;
		cola->head->ant = NULL;
		x = cabeza->valor;
		cola->cuenta--;
		free(cabeza);
	}
	return x;
}

void display (QUEUE *cola, int orden){
	if(cola->cuenta==0){
		printf("la cola se encuentra vacia\n");
	}else{
		NODO *ptr=NULL;
		if(orden==HEAD){
			ptr = cola->head;
			while(ptr!=NULL){
				printf("%d:",ptr->valor);
				ptr=ptr->sig;
			}
		}else{
			ptr=cola->tail;
			while(ptr!=NULL){
				printf("%d:",ptr->valor);
				ptr=ptr->ant;
			}
		}
		printf("\n");
	}
}