#include <time.h>
#define MAXVERTICES 5
#define MAXWEIGHT 10
#define TRUE 1
#define FALSE 0

// function rand_interval from: http://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range

typedef struct Edge{
    int vertice;
    int weight;
    struct Edge *sige;
}EDGE;

typedef struct Vertice{
    int vertice;
    int visto;
    struct Edge *sige;
    struct Vertice *sigv;
}VERTICE;

typedef struct grafo{
    int num_vertices;
    struct Vertice *head;
} GRAPH;

GRAPH * crear_grafo(int size);
void insert(GRAPH *grafo);
void insert_edge(GRAPH *grafo, int from, int to, int weight);
void display(GRAPH *grafo);
void display_edges(EDGE *e);
EDGE * get_edge(EDGE *e, int to);
EDGE * existe_edge(GRAPH *g, int from, int to);
VERTICE * get_vertice(GRAPH *grafo, int vertice);
unsigned int rand_interval(unsigned int min, unsigned int max);

VERTICE * get_vertice(GRAPH *grafo, int vertice) {
    VERTICE *p = grafo->head;
    while(p != NULL) {
        if(p->vertice == vertice) {
            return p;
        }
        p = p -> sigv;
    }
    return NULL;
}

GRAPH * crear_grafo(int size) {
    if(size < 1) {
        return NULL;
    } else {
        int i = 0;
        GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));
        if(g != NULL) {
            g->num_vertices = size;
            VERTICE *v = (VERTICE *)malloc(sizeof(VERTICE));
            g->head = v;
            VERTICE *p = g->head;
            p->vertice = 1;
            p->visto = FALSE;
            p->sige = NULL;
            for(i = 2; i <= size; i++) {
                p->sigv = (VERTICE *)malloc(sizeof(VERTICE));
                p = p->sigv;
                p -> vertice = i;
                p -> visto   = FALSE;
                p -> sige    = NULL;
                p -> sigv    = NULL;
            }
        }
        return g;
    }
}

void insert_edge(GRAPH *grafo, int from, int to, int weight) {
    VERTICE *p = grafo->head;
    while(p != NULL ) {
        if(p -> vertice == from ) {
            if(p->sige == NULL) {
                EDGE *edge = (EDGE *) malloc( sizeof( EDGE ) );
                edge -> vertice = to;
                edge -> weight  = weight;
                edge -> sige    = NULL;
                p->sige = edge;
            } else {
                EDGE *edge = p -> sige;
                edge = get_edge(p -> sige, to);
                if(edge != NULL) {
                    edge -> weight = weight;
                } else {
                    EDGE *new_edge = (EDGE *) malloc( sizeof( EDGE ) );
                    new_edge -> vertice = to;
                    new_edge -> weight  = weight;
                    new_edge -> sige    = p->sige;
                    p -> sige = new_edge;
                }
            }
        }
        p = p -> sigv;
    }
}

EDGE * existe_edge(GRAPH *g, int from, int to) {
    VERTICE *p = g->head;
    while(p != NULL) {
        if(p->vertice == from) {
            EDGE *edge = get_edge( p->sige, to);
            return edge;
        }
        p = p -> sigv;
    }
    return NULL;
}

EDGE * get_edge(EDGE *e, int to) {
    EDGE *p = e;
    while(p != NULL) {
        if(p->vertice == to ) {
            return p;
        }
        p = p->sige;
    }
    return NULL;
}

void display(GRAPH *grafo) {
    VERTICE *p = grafo->head;
    printf("\nVert | edges\n");
    printf("------------\n");
    while(p != NULL) {
        printf("%d    |", p->vertice);
        display_edges(p->sige);
        p = p -> sigv;
    }
}

void display_edges(EDGE *e) {
    EDGE *p = e;
    while(p != NULL) {
        printf("\t%d:%d", p->vertice, p->weight);
        p = p->sige;
    }
    printf("\n");
}

void insert(GRAPH *grafo) {
    int A, B, weight;
    srand(time(0)); /* inicializar el generador de numeros aleatorios */
    int no_edges = MAXVERTICES*MAXVERTICES;
    //printf("Edges:%d\n", no_edges );
    for(int i = 1; i <= no_edges; i++) {
        A = rand_interval(1, MAXVERTICES);
        B = rand_interval(1, MAXVERTICES);
        weight = rand_interval(1, MAXWEIGHT);
        //printf("%d->%d:%d\n", A, B, weight);
        insert_edge(grafo, A, B, weight);
    }
 }

unsigned int rand_interval(unsigned int min, unsigned int max) {
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;
	
    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do {
        r = rand();
    } while(r >= limit);
    return min + (r / buckets);
}