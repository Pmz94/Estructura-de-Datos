/* Autor Pedro Muñoz
Fecha 4 de Septiembre de 2015
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct nodo{
	int valor;
	struct nodo *sig;
}Nodo;

Nodo* inicializar_pila(void);
void insertar_argumentos(Nodo **pila, int size, char **array);
void push (Nodo **pila, int v);
Nodo * Nuevo_nodo(void);
void display(Nodo * pila);
int pop(Nodo **pila);

int main(int argc, char **argv){
	Nodo *stack=NULL;
	int x;
	stack = inicializar_pila();
	insertar_argumentos(&stack, argc, argv);
	display(stack);
	x = pop(&stack);
	printf("x =  %d \n",x);
	display(stack);
}

Nodo* inicializar_pila(void){
	return NULL;
	
}

void insertar_argumentos(Nodo **pila, int size, char **array){
	for(int i=1; i<size; i++){
		if(isdigit(*array[i])){
			push(pila, atoi(array[i]));
		}
	}
}

void push (Nodo **pila, int v){
	Nodo *temp=NULL;
	temp= Nuevo_nodo();
	if(*pila==NULL){
		temp->valor=v;
		temp->sig=NULL;
		*pila=temp;
	}
	else {
		temp->valor=v;
		temp->sig=*pila;
		*pila=temp;
	}
}

Nodo * Nuevo_nodo(void){
	Nodo * ptr=NULL;
	ptr=(Nodo *)malloc(sizeof(Nodo));
	if(ptr==NULL){
		return NULL;
	}else{
		ptr->valor=0;
		ptr->sig=NULL;
		return ptr;
	}
}
void display(Nodo * pila){
	Nodo * ptr=pila;
	while(ptr!=NULL){
		printf("%d ",ptr->valor);
		ptr=ptr->sig;
	}
	printf("\n");
}

int pop(Nodo **pila){
	int numero = -1;
	if(*pila!=NULL){
		Nodo *temp=*pila;
		numero=temp->valor;
		*pila=temp->sig;
		free(temp);
	}
	return numero;
}