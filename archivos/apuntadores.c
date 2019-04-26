/* apuntadores.c - Pedro Munoz - 19/Agosto/2015 */
#include <stdio.h> //standard input/output

void f(int *a, int *b);
void set_x_and_y(int *x, int *y);

int main(int argc, char **argv) {
	int a_inicial = 10;
	int b_inicial = 20;
	printf("a: %d\nb:%d\n", a_inicial, b_inicial);
	f(&a_inicial, &b_inicial);
	printf("a:%d\nb:%d\n", a_inicial, b_inicial);

	return 0;
}

void set_x_and_y(int *x, int *y) {
	*x = 1001;
	*y = 1002;
}

void f(int *a, int *b) {
	int *a = 1;
	int *b = 2;
	//set_x_and_y(&a,&b)
}