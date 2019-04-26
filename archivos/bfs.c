/* bfs.c - Pedro Muñoz - 29/Noviembre/2015 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "grafo.h"

void mark_it_as_seen(GRAPH *grafo, int v);
void put_adjacent_vertices_not_seen(QUEUE **q, GRAPH *grafo, int v);
void bfs(GRAPH *g, int start_vertice, int end_vertice);

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

        bfs(grafo, A, B);

    }
}

void bfs(GRAPH *g, int start_vertice, int end_vertice) {
    int encontrado = FALSE;
    int vertice;
    QUEUE *Q = createQueue();
    put(Q, start_vertice);
    do {
        vertice = get(Q);
        if(vertice == end_vertice) {
            encontrado == TRUE;
        } else {
            printf("vertice:%d visto\n", vertice);
            mark_it_as_seen(g, vertice);
            put_adjacent_vertices_not_seen(&Q, g, vertice);
            display_queue(Q);
            printf("\n");
        }
    } while (( Q->size > 0) && (!encontrado));

    if(encontrado = TRUE) {
        printf("Si existe camino entre %d y %d\n", start_vertice, end_vertice);
    } else {
        printf("NO existe camino entre %d y %d\n", start_vertice, end_vertice);
    }
}

void mark_it_as_seen(GRAPH *grafo, int v) {
    VERTICE *p = get_vertice(grafo, v);

    if(p != NULL) {
        p->visto = TRUE;
    }
}

void put_adjacent_vertices_not_seen(QUEUE **q, GRAPH *grafo, int v) {
    VERTICE *w; //vertice auxiliar
    VERTICE *p = get_vertice(grafo, v);

    if(p != NULL) {
        EDGE *e = p->sige;
        while(e != NULL) {
            w = get_vertice(grafo, e->vertice);
            if(w->visto == FALSE) {
                put(*q, w->vertice);
            }
            e = e->sige;
        }
    }
}