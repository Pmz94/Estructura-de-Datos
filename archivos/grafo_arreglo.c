/* grafo_arreglo.c - Pedro Muñoz - 5/Noviembre/2015 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVERTICES 5
#define MAXMATRICES 6
#define MAXWEIGHT 10
#define TRUE 1
#define FALSE 0

typedef struct grafo_arreglo {
	int vertices[MAXMATRICES];
	int edges[MAXVERTICES][MAXMATRICES];
} Graph;

Graph *inicializar_grafo(void);
void display(Graph *grafo);
unsigned int rand_interval(unsigned int min, unsigned int max);
void insert_edge(Graph* grafo, int from, int to, int weight);
void insert(Graph* grafo);
int existe_edges(Graph* grafo, int from, int to);

int main(int argc, char **argv) {
	int A, B;
	if(argc >= 2) A = atoi(argv[1]);
	if(argc >= 3) B = atoi(argv[2]);
	srand(time(0)); 				//inicializar numeros aleatorios
	Graph *g = inicializar_grafo();
	display(g);
	insert(g);
	display(g);
	if(existe_edges(g, A, B) == TRUE) {
		printf("%d->%d Existe\n", A, B);
	} else {
		printf("%d->%d No Existe\n", A, B);
	}
}

Graph *inicializar_grafo(void) {
	Graph *grafo = NULL;
	grafo = (Graph *)malloc(sizeof(Graph)); //pedimos memoria
	if(grafo != NULL) {
		for(int i = 1; i < MAXVERTICES; i++) {
			grafo->vertices[i] = i;
		}
		for(int j = 1; j < MAXVERTICES; j++) {
			for(int i = 1; i < MAXVERTICES; i++) {
				grafo->edges[j][i] = 0;
			}
		}
	}
	return grafo;
}

void display(Graph *grafo) {
	int i, j;
	printf("Vertices\n----------------\n");
	for(i = 1; i < MAXVERTICES; i++) {
		printf("%d:\n", grafo->vertices[i]);
	}
	printf("\n");
	printf("Edges\n----------------\n");
	
	for(i = 1; i < MAXVERTICES; i++) {
		printf("\t%d:", i);
	}
	printf("\n");
	
	for(j = 1; j < MAXVERTICES; j++) {
		printf("%d", j);
		for(i = 1; i < MAXVERTICES; i++) {
			printf("\t%d", grafo->edges[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

unsigned int rand_interval(unsigned int min, unsigned int max) {
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    do {
		r = rand();
    } while(r >= limit);
    return min + (r / buckets);
}

void insert_edge(Graph* grafo, int from, int to, int weight) {
	if(grafo != NULL) {
		if((from > 0) && (from < MAXVERTICES)) {
			if((to > 0) && (to < MAXVERTICES)) {
				grafo->edges[from][to] = weight;
			}
		}
	}
}

void insert(Graph* grafo) { // inserta los valores
	int A, B, peso;
	int num_edges = MAXVERTICES * MAXVERTICES;
	for(int i = 1; i < num_edges; i++) {
		A = rand_interval(1, MAXVERTICES);
		B = rand_interval(1, MAXVERTICES);
		peso = rand_interval(1, MAXWEIGHT);
		insert_edge(grafo, A, B, peso);
	}
}

int existe_edges(Graph* grafo, int from, int to) {
	if(grafo != NULL) {
		if((from > 0) && (from < MAXVERTICES)) {
			if((to > 0) && (to < MAXVERTICES)) {
				if(grafo->edges[from][to] > 0) {
				return TRUE;
				}
			}
		}
	}
	return FALSE;
}