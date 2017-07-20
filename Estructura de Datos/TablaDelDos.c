/* autor Pedro Munoz
Fecha 13 de Agosto de 2015
*/
#include<stdio.h> //standard input/output

int main (int argc, char **argv){
	
	int i;
	int tablas[10];
	
	for(i=1; i<=10; i++){
		tablas[i]=i*2;
	}
		for(i=1; i<=10; i++){
			printf("2*%d=%d\n",i,tablas[i]);
		}
}