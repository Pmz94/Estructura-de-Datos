/* insertaarreglo.c - Pedro Muñoz - 7/Octubre/2015 */

#include <stdio.h>
#include <ctype.h>

#define MAXARRAY 20
#define TRUE 1
#define FALSE 0
#define IZQUIERDA 0
#define DERECHA 1

void inserta_argumentos(int *array, int size, char **argumento);
void ordena(int *arreglo, int size);
void display(int *arreglo, int size);
void busqueda_simple(int *arreglo, int size, int a_buscar);
void busqueda_binaria(int *arreglo, int size, int key);
void insertar_valor(int *arreglo, int *size, int valor);
int mover(int *arreglo, int pos, int *lim, int direccion);

int main(int argc, char **argv) {
	int s = argc;
	int array[MAXARRAY];
	if(argc < MAXARRAY) {
		inserta_argumentos(array, argc, argv);
		display(array, argc);
		ordena(array, argc);
		display(array, argc);
		busqueda_simple(array, argc, 8);
		insertar_valor(array, &s, 8);
		mover(array, s);
	}
	return 0;
}

void inserta_argumentos(int *array, int size, char **argumento) {
	int temp;
	for(int i = 1; i < size; i++) {
		if(isdigit(*argumento[i])) {
			temp = atoi(argumento[i]);
			array[i] = temp;
		}
	}
}

void ordena(int *array, int size) {
	int tmp;
	for(int j = 1; j < size; j++) {
		for(int i = 1; i < (size - 1); i++) {
			if(array[i] > array[i + 1]) {
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
		}
	}
}

void display(int *array, int size) {
	for(int j = 1; j < size; j++) {
		printf("%d:", array[j]);
	}
	printf("\n");
}

void busqueda_simple(int *arreglo, int size, int a_buscar) {
	int encontrado = FALSE;
	for(int i = 1; i < size; i++) {
		if(arreglo[i] == a_buscar) {
			printf("Se encontro %d, En Posicion %d\n", a_buscar, i);
			encontrado = TRUE;
			break;
		}
	}
	if(encontrado == FALSE) {
		printf("No Se Encontraron Coincidencias");
	}
}

void busqueda_binaria(int *arreglo, int size, int key) {
	int izq = 0;
	int der = size;
	int mitad;
	int encontrado = FALSE;
	int count = 0;
	
	while(izq <= der) {
		mitad = (izq + der) / 2;
		if(arreglo[mitad] > key) {
			der = mitad - 1;
			count++;
		} else {
			if(arreglo[mitad] < key) {
				izq = mitad + 1;
				count++;
			} else {
				count++;
				printf("Encontrado! Num. %d en posicion %d\n", key, count);
				encontrado = TRUE;
				break;
			}
		}
	}
}

void insertar_valor(int *arreglo, int *size, int valor) {
	for(int i = 1; i < *size - 1; i++) {
		if(valor > arreglo[i]) {
			if(valor <= arreglo[i + 1]) {
				mover(arreglo, (i + 1), size, DERECHA);
				arreglo[i + 1] = valor;
				break;
			}
		}
	}
}

int mover(int *arreglo, int pos, int *lim, int direccion) {
	int i;
	int tmp1;
	int tmp2;
	if(direccion == DERECHA) {		//abriendo un lugar
		if((*lim + 1) < MAXARRAY) {
			tmp1 = arreglo[pos];
			arreglo[pos] = 0;
			for(i = pos; i < (*lim + 1); i++) {
				tmp2 = arreglo[i + 1];
				arreglo[i + 1] = tmp1;
				tmp1 = tmp2;
			}
			*lim = (*lim + 1);
		}
	}
}