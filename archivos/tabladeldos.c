/* Pedro Munoz - 13/Agosto/2015 */
#include <stdio.h> //standard input/output

/*int main(int argc, char **argv) {	
	int i;
	int tablas[10];
	
	for(i = 1; i <= 10; i++) {
		tablas[i] = i * 2;
		printf("2 * %d = %d\n", i, tablas[i]);
	}
}*/

int main() {
    int n, i;
	char t;

    printf("Tabla del: ");
    //scanf("%d",&n);

	if(scanf("%d%c",&n, &t) != 2 || t != '\n') {
		printf("ESCRIBA UN NUMERO!\n");
		return 0;
	}

    for(i = 1; i <= 10; ++i) {
    	printf("%d * %d = %d \n", n, i, n * i);
    }
    return 0;
}