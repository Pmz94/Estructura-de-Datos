/* autor Pedro Munoz
Fecha 17 de Agosto de 2015
*/
#include<stdio.h> //standard input/output
 
int main (int argc, char **argv){
	
	int j,i;
	int tabla[11][11];
		
	for(i=0; i<11; i++){		//renglones
		for(j=0; j<11; j++){	//columnas
			tabla[i][j]=i*j;
		}
	}
		
	for(i=0; i<11; i++){		//renglones
		for(j=0; j<11; j++){	//columnas
			printf("%d x %d = %d \n",i,j,tabla[i][j]);
		}
	}
	return 0;
}