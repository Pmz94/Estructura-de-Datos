/* grafo_lista
Autor: Pedro Muñoz
Fecha: 10 de Noviembre de 2015
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXVERTICES 5
#define MAXMATRICES 6
#define MAXWEIGHT 10
#define TRUE 1
#define FALSE 0

typedef struct Edge{
	int vertice;
	int weight;
	struct Edge *sige; //siguiente edge
}EDGE;

typedef struct Vertice{
	int vertice;
	struct Edge *sige;		//siguiente edge
	struct Vertice *sigv; 	//siguiente vertice
}VERTICE;

typedef struct grafo{
	int num_vertices;
	struct Vertice *head;
}GRAFO;

unsigned int rand_interval(unsigned int min, unsigned int max);
GRAFO * inicializar_grafo(int size);
void insert_edge(GRAFO * g, int from, int to, int weight);
EDGE *get_edge(EDGE *e, int to);
void insert(GRAFO *g);
void display(GRAFO* g);
void display_edges(EDGE* e);
EDGE * existe_edge(GRAFO *g, int from, int to);

int main(int argc, char **argv){
	int A,B,tmp;
	GRAFO *g=NULL;
	EDGE *e=NULL;
	if(argc>=2) A=atoi(argv[1]);
	if(argc>=3) B=atoi(argv[2]);
	srand(time(0));
	g = inicializar_grafo(MAXVERTICES);
	if(g != NULL){
		insert(g);
		display(g);
		e = existe_edge(g,A,B);
		if(e != NULL){
			printf("Si existe arco entre %d y %d. su peso es %d\n",A,B,e->weight);
		}else{
			printf("No existe arco entre %d y %d.",A,B);
		}
		
	}
	return 0;
}

unsigned int rand_interval(unsigned int min, unsigned int max){
    int r;
    const unsigned int range=1+max-min;
    const unsigned int buckets=RAND_MAX/range;
    const unsigned int limit=buckets*range;

    do{
		r=rand();
    }while(r>=limit);
    return min+(r/buckets);
}

GRAFO * inicializar_grafo(int size){
	if(size>0){
		int i;
		GRAFO *g = (GRAFO*)malloc(sizeof(GRAFO));
		if(g != NULL){
			g->num_vertices = size;
			VERTICE *v = (VERTICE*)malloc(sizeof(VERTICE));
			g->head = v;
			VERTICE *tmp = v;
			tmp->vertice = 1;
			tmp->sige = NULL;
			for(i=2;i<=g->num_vertices;i++){
				tmp->sigv	=(VERTICE*)malloc(sizeof(VERTICE));
				tmp			=tmp->sigv;
				tmp->vertice =i;
				tmp->sige	=NULL;
			}
		}
		return g;
	}else{
		return NULL;
	}
}

void insert_edge(GRAFO * g, int from, int to, int weight){
	VERTICE *p = g->head;
	while(p != NULL){
		if(p->vertice==from){
			if(p->sige==NULL){
				EDGE *edge		= (EDGE*)malloc(sizeof(EDGE));
				edge->vertice	= to;
				edge->weight	= weight;
				edge->sige		= NULL;
				p->sige			= edge;
			}else{
				EDGE* edge = p->sige;
				edge = get_edge(p->sige, to);
				if(edge != NULL){
					edge->weight = weight;
				}else{
					EDGE * new_edge		= (EDGE*)malloc(sizeof(EDGE));
					new_edge->vertice 	= to;
					new_edge->weight	= weight;
					new_edge->sige		= p->sige;
					p->sige				= new_edge;
				}
			}
		}
		p=p->sigv;
	}
}

EDGE *get_edge(EDGE *e, int to){
	EDGE *p = e;
	while (p != NULL){
		if(p->vertice == to){
			return p;
		}
		p = p->sige;
	}
	return NULL;
}

void insert(GRAFO *g){		//inserta los valores
	int A,B,peso;
	int num_edges =MAXVERTICES * MAXVERTICES;
	for(int i=1; i<=num_edges; i++){
		A=rand_interval(1,MAXVERTICES);
		B=rand_interval(1,MAXVERTICES);
		peso=rand_interval(1,MAXWEIGHT);
		insert_edge(g,A,B,peso);
	}
}

void display(GRAFO* g){
	VERTICE *p = g->head;
	printf("Vertice | Edges\n\n");
	printf("\n");
	while(p != NULL){
		printf("%d\n", p->vertice);
		display_edges(p->sige);
		p = p->sigv;
	}
}

void display_edges(EDGE* e){
	if(e!=NULL){
		EDGE * p = e;
		while(p!=NULL){
			printf("\t %d:%d", p->vertice,p->weight);
			p = p->sige;
		}
		printf("\n");
	}
}

EDGE * existe_edge(GRAFO *g, int from, int to){
	VERTICE *p = g->head;
	EDGE *e = NULL;
	while(p != NULL){
		if(p->vertice == from){
			e = get_edge(p->sige, to);
			break;
		}
		p = p->sigv;
	}
	return e;
}