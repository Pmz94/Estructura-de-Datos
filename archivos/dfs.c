/*
function dfs() from: http://en.wikipedia.org/wiki/Depth-first_search
Federico Cirett 
18/Noviembre/2015
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "grafo.h"

void dfs(GRAPH *g, int start_vertice, int end_vertice);
void mark_it(GRAPH *grafo, int v);
void push_adjacent_vertices(NODO **S, GRAPH *grafo, int v);

int main(int argc, char **argv) {
    int vertices = MAXVERTICES;
    int A = 5, B = 4;
    if(argc >= 2) A = atoi(argv[1]);
    if(argc >= 3) B = atoi(argv[2]);
    srand(time(0));//inicializar numeros aleatorios
    GRAPH *grafo = NULL;
    grafo = crear_grafo(vertices);
    if(grafo != NULL) {
        insert(grafo);
        display(grafo);
        dfs(grafo, A, B);
    }
    return 0;
}

void dfs(GRAPH *g, int start_vertice, int end_vertice) {
	int encontrado = FALSE;
	int vertice;
	NODO *S = NULL;		//declaramos nuestro STACK
	push(&S, start_vertice);	//empezamos con el vertice inicial
	do {
		vertice = pop(&S);
		if(vertice == end_vertice) {
			encontrado = TRUE;
		} else {
			printf("vertice %d visto\n", vertice);
			mark_it(g, vertice);		//marcar como visto
			push_adjacent_vertices(&S, g, vertice);
			display_stack(S);
			printf("\n");
		}
	} while((S != NULL) && (!encontrado));
	if(encontrado == TRUE) {
		printf("SI existe camino entre %d y %d\n", start_vertice, end_vertice);
	} else {
		printf("NO existe camino entre %d y %d\n", start_vertice, end_vertice);
	}
}

void mark_it(GRAPH *grafo, int v) {
    VERTICE * p =  get_vertice(grafo, v);
	if(p != NULL) {
		p->visto = TRUE;
	}
}

void push_adjacent_vertices(NODO **S, GRAPH *grafo, int v) {
    VERTICE * w;
	VERTICE * p = get_vertice(grafo, v);
	if(p != NULL) {
		EDGE * e = p->sige;
		while(e != NULL) {
			w = get_vertice(grafo, e->vertice);
			if(w->visto == FALSE) {
				push(S, w->vertice);
			}
			e = e->sige;
		}
	}
}