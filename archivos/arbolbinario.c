/* Pedro Muñoz - 26/Octubre/2015 */
#include <stdio.h>
#include <stdlib.h>

typedef int Key;	//defininiendo tipo de dato llamado key que es entero
typedef struct nodo Link;	// definiendo una estrcutura tipo apuntador link
typedef struct nodo{
	Key id;
	Link *izq;
	Link *der;
}Nodo;

void carga_datos(Nodo **tree, int size, char **array);
void insert(Nodo ** tree, Key valor);
void display_inorder(Nodo *t);
void display_reverse(Nodo *t);
void display_preorder(Nodo *t);
void display_postorder(Nodo *t);
void display(Key valor);

int main(int argc,char **argv) {
	Nodo *raiz = NULL;
	carga_datos(&raiz, argc, argv);
	printf("In Order \n");
	display_inorder(raiz);
	printf("\n");
	printf("Reverse Order \n");
	display_reverse(raiz);
	printf("\n");
	printf("Pre Order \n");
	display_preorder(raiz);
	printf("\n");
	printf("Post Order \n");
	display_postorder(raiz);
	printf("\n");
	return 0;
}

void carga_datos(Nodo **tree, int size, char **array) {
	for(int i = 1; i < size; i++) {
		insert(tree, atoi(array[i]));
	}
}

void insert(Nodo ** tree, Key valor) {
	Nodo *tmp = NULL;
	if(*tree == NULL) {
		tmp = (Nodo *) malloc(sizeof(Nodo));
		tmp->id = valor;
		tmp->izq = NULL;
		tmp->der = NULL;
		*tree = tmp;
	} else {
		if(valor < (*tree)->id) {
			insert(&(*tree)->izq, valor);
		} else {
			if(valor > (*tree)->id) {
				insert(&(*tree)->der, valor);
			}
		}
	}
}

void display_inorder(Nodo *t) {
	if(t != NULL) {
		display_inorder(t->izq);
		display(t->id);
		display_inorder(t->der);
	}
}

void display_reverse(Nodo *t) {
	if(t != NULL) {
		display_reverse(t->der);
		display(t->id);
		display_reverse(t->izq);
	}
}

void display_preorder(Nodo *t) {
	if(t != NULL) {
		display(t->id);
		display_preorder(t->izq);
		display_preorder(t->der);
	}
}

void display_postorder(Nodo *t) {
	if(t != NULL) {
		display_postorder(t->izq);
		display_postorder(t->der);
		display(t->id);
	}
}

void display(Key valor) {
	printf("%d ", valor);
}