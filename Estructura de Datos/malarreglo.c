/* autor Pedro Munoz
Fecha 13 de Agosto de 2015
*/
#include<stdio.h> //standard input/output

int main (int argc, char **argv)
{
	int a=5;
	int array[3];
	int b = 10;
	int i;
	
	for(i=0; i<3;i++){
		array[i]=i;
	}
	
	array[-1]=7;
	printf("a:%ld\n",a);
	printf("b:%ld\n",b);
	for(i=0;i<3;i++){
		printf("a[%d]:%d\n",i,array[i]);
	}
}