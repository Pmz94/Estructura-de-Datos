/* Pedro Muñoz
	26/Noviembre/2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#define MAXLEN 30

void carga_nombres(NODO **tree, int argc, char **argv);

int main( int argc, char **argv){
  NODO *raiz = NULL;
  carga_nombres(&raiz,argc, argv);
  print_inorder(raiz);
  exit(0);
}

void carga_nombres(NODO **tree, int argc, char **argv){
	FILE *fp;
	char nombre[MAXLEN];
	char apellido[MAXLEN];
	char nombre_completo[MAXLEN+MAXLEN];
	if(argc >= 2){
		char *filename = strdup(argv[1]);
		fp=fopen(filename,"r");
		if(fp!=NULL){
			while(!feof(fp)){	//feof(fp) == FALSE
				if(fscanf(fp, "%s %s", nombre,apellido)!=2){
					break;
				}
				strcpy(nombre_completo,nombre);
				strcat(nombre_completo," ");
				strcat(nombre_completo,apellido);
				insert((tree),nombre_completo);
			}
			fclose(fp);
		}
	}
}
