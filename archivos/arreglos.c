/* arreglos.c - Pedro Munoz - 21/Agosto/2015 */
#include <stdio.h> //standard input/output
#define VALORMAX 10

void imprime_arreglo(int array[], int size);
void agregar_valores(int array[], int size);
void imprime_apuntador(int *array, int size);

int main(int argc, char **argv) {
	int valor [VALORMAX];
	int *punto;
	agregar_valores(valor, VALORMAX);
	imprime_arreglo(valor, VALORMAX);
	imprime_apuntador(valor, VALORMAX);
	
	return 0;
}

void imprime_arreglo(int array[], int size) {	
	for(int i = 0; i < 10; i++) {
		printf("i: %d = %d\n", i, array[i]);
	}
}

void agregar_valores(int array[], int size) {
	for(int i = 0; i < size; i++) {
		array[i] = i;
	}
}

void imprime_apuntador(int *array, int size) {
	int *p;
	for(p = array; p < &array[size]; p++) {
		printf("p = %d * p = %d\n", p, *p);
		//*array = *(array + 1);
	}
}