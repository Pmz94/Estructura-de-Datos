/* Pedro Munoz - 24/Agosto/2015 */
#include <stdio.h>

int main(int argc, char **argv) {
	for(int i = 0; i < argc; i++) {
		printf("i: %d argv: %s\n:", i, argv[i]);
	}
	return 0;
}