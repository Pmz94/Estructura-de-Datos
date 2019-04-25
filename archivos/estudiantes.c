/* autor Pedro Munoz
Fecha 25 de Agosto de 2015
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct estudiantes{
	char nombre[20];
	float calificacion;
	struct estudiantes *sig;
}	Student;

Student * insert(int argc, char **argv);
Student * nuevo_nodo(void);
void display(Student * head);
 
unsigned int rand_interval(unsigned int min, unsigned int max){
	int r;
	const unsigned int range = 1 + max - min;
	const unsigned int buckets = RAND_MAX / range;
	const unsigned int limit = buckets * range;
	/* Cree cubos de igual tamaño todos en una sola fila, luego dispare al azar hacia 
	   los cubos hasta aterrizar en uno de ellos. Todos los cubos son equiprobables. 
	   Si aterriza en el borde de la línea de cubos, vuelva a intentarlo. */
	do{
		r=rand();
	}while (r>=limit);
	return min+(r/buckets);
	}
 
int main(int argc, char **argv){
	Student *raiz = NULL;
	raiz = insert(argc, argv);
	display (raiz);
	return 0;
 }
 
Student * insert(int size, char **array){
	Student *head = NULL;
	Student *ptr = NULL;
	head = nuevo_nodo(); //crear espacio en la memoria, recibimos nombres y calif al mismo campo
	ptr = head; //dos variables que apuntan a la misma ubicacion
		for(int i=1; i<size; i++){
			strcpy(ptr->nombre, array[i]);
			ptr->calificacion=(float)rand_interval(60,100);
			if(!(i==size)){
				ptr->sig=nuevo_nodo();
				ptr=ptr->sig;
			}
		}
	return head;
 }

Student * nuevo_nodo(void){
	Student* p;
	p=(Student*)malloc(sizeof(Student));
	p->calificacion=0;
	p->sig=NULL;
	return p;
}
 
void display(Student * head){
	Student * ptr = head;
	while(ptr->sig!=NULL){
		printf(" %s %f\n",ptr->nombre,ptr->calificacion);
		ptr=ptr->sig;
	}
}