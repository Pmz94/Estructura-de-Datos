/* Pedro Munoz - 17/Agosto/2015 */
#include <stdio.h> //standard input/output

int main(int argc, char **argv) {
	int j, i;
	int tabla[11][11];
		
	for(i = 0; i < 11; i++) {		//renglones
		printf("Tabla del %d:\n", i);
		for(j = 0; j < 11; j++) {	//columnas
			tabla[i][j] = i * j;
			printf("%d * %d = %d\n", i, j, tabla[i][j]);
		}
		printf("\n");
	}
	return 0;
}