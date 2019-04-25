/* Pedro Munoz - 31/Agosto/2015 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct elementos{
	int valor;
	struct elementos *sig;
}Nodo;

Nodo* insertar_argumentos(int size, char **array);
void display(Nodo * head);
Nodo * nuevo_nodo(void);
Nodo *ordenar(Nodo *inicio, int ordenar);

#define ASCENDENTE 1
#define DESCENDENTE 2
int main (int argc, char **argv){
	Nodo* raiz;
	raiz = insertar_argumentos(argc, argv);
	//display(raiz);
	ordenar(raiz, ASCENDENTE);
	display(raiz);
	ordenar(raiz, DESCENDENTE);
	display(raiz);
	return 0;
}

Nodo* insertar_argumentos(int size, char **array){
	Nodo *head = NULL;
	Nodo *ptr = NULL;
	head = nuevo_nodo(); //crear espacio en la memoria, recibimos nombres y calif al mismo campo
	ptr = head; //dos variables que apuntan a la misma ubicacion
	
	for(int i = 1; i < size; i++) {
		ptr->valor = atoi(array[i]);
			
		if(!(i == size - 1)) {
			ptr->sig = nuevo_nodo();
			ptr = ptr->sig;
		}
	}
	return head;
}

void display(Nodo * head){
	Nodo* ptr = head;
	while(ptr!=NULL){
		printf("%d \n",ptr->valor);
		ptr=ptr->sig;
	}
	printf("\n");
}

Nodo * nuevo_nodo(void){
	Nodo * p =NULL;
	p=(Nodo*)malloc(sizeof(Nodo));
	p->valor = 0;
	p->sig = NULL;
	return p;
}

Nodo *ordenar(Nodo *inicio, int ordenar){
	Nodo *temp, *temp1;
	
	for(temp=inicio; temp!=NULL; temp=temp->sig){
		for(temp1=temp->sig; temp1!=NULL; temp1=temp1->sig){
			if(ordenar== ASCENDENTE){
				if(temp->valor > temp1->valor){
					int t=temp->valor;
					temp->valor=temp1->valor;
					temp1->valor=t;
				}
			}else{
				int t=temp->valor;
				temp->valor=temp1->valor;
				temp1->valor=t;
			}
		}
	}
	return inicio;
}