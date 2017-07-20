/*Autor Pedro Muñoz
Fecha 19 de Octubre de 2015
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define YAEXISTE 2

typedef struct linked_list{
	char *string;
	int hashvalue;
	float calificacion;
	struct linked_list *sig;
}LINKED;

typedef struct hashtable{
	int size;
	LINKED **table;
}HASHTABLE;

HASHTABLE *create_hash_table(int size);
void carga_valores(HASHTABLE *ht, int argc, char** argv);
int add_string(HASHTABLE *hashtable, char *str);
LINKED * lookup_string(HASHTABLE *hashtable, char *str);
unsigned int hash(HASHTABLE *hashtable, char *str);
void display(HASHTABLE *ht);

int main(int argc,char **argv){
	char *persona=NULL;
	HASHTABLE *my_ht=NULL;
	int size_of_table=12;
	LINKED *nodo=NULL;
	
	if(argc>=2){
		persona = strdup(argv[1]);
	}
	if(argc>=3){
		size_of_table = atoi(argv[2]);
	}
	//crear hashtable
	my_ht = create_hash_table(size_of_table);
	//cargar los nombres
	carga_valores(my_ht, argc, argv);
	//despliega la hashtable
	display(my_ht);
	nodo = lookup_string(my_ht, persona);
	if(nodo!=NULL){
		printf("\nEncontrada: %u: %s\n",nodo,nodo->string);
	}
	return 0;
}

HASHTABLE *create_hash_table(int size){
	
	int i;
	HASHTABLE *new_table;
	//checar el tamaño de la tabla
	if(size < 1) return NULL; //tamaño invalido
	//pedimos memoria para la tabla
	if((new_table = (HASHTABLE*)malloc(sizeof (HASHTABLE))) == NULL){
		return NULL; //si malloc no da memoria regresamos
	}
	//pedimos memoria para cafa primer elemento en la tabla
	if((new_table->table = malloc(sizeof (LINKED *) * size))== NULL ){
		return NULL; //si malloc no da memoria regresamos
	}
	//inicializamos los elementos en NULL
	for(i=0; i< size; i++){
		new_table->table[i]= NULL;
	}
	//grabamos el nuevo tamaño de la tabla
	new_table->size= size;
	return new_table;
}

void carga_valores(HASHTABLE *ht, int argc, char** argv){
	int i;
	for(i= 3; i<argc; i++){
		add_string(ht, argv[i]);
	}
}

int add_string(HASHTABLE *hashtable, char *str){
	LINKED *new_list;
	LINKED *current_list;
	unsigned int hashval = hash(hashtable, str);
	//intenta obtener memoria para el elemento de la lista
	if(( new_list = (LINKED*)malloc(sizeof(LINKED)))==NULL){
		return 1;
	}
	current_list = lookup_string(hashtable, str);
	//si el elemento ya existe, no hay que agregarlo de nuevo
	if(current_list!=NULL){
		return YAEXISTE;
	}
	//insertar en la lista
	new_list->string 	= strdup(str);
	new_list->hashvalue = hashval;
	new_list->sig 		= hashtable->table[hashval];
	hashtable->table[hashval] = new_list;
	return 0;
}

LINKED * lookup_string(HASHTABLE *hashtable, char *str){
	LINKED *list;
	unsigned int hashval = hash(hashtable, str);
	//ve a la lista correcta basada en el valor del hash
	//si la cadena esta en la lista, regresa un apuntador a la lista
	//si no, avanza por la lista ligada hasta encoontar NULL
	for(list=hashtable->table[hashval]; list != NULL; list = list->sig){
		if(strcmp(list->string, str)==0) return list;
	}
	return NULL;
}

unsigned int hash(HASHTABLE *hashtable, char *str){
	unsigned int hashval= 0;
	for(; *str != '\0'; str++){
		hashval = *str + (hashval << 5) - hashval;
	}
	return (hashval % hashtable-> size);
}

void display(HASHTABLE *ht){
	int i;
	LINKED *n;
	for(i=0; i<ht->size; i++){
		if(ht->table[i] != NULL){
			printf("%u:\n",ht->table[i]);
			n = ht->table[i];
			while(n != NULL){
			printf("\t%u (%d) %s\n",n,n->hashvalue,n->string);
			n = n->sig;
			}
		}
	}
}