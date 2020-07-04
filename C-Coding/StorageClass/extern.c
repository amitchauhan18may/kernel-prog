#include <stdio.h>

int main (void) {

	int e = 5;
	extern int r;
	printf("%d\n", e);
	printf("%d\n", r);
}

int r = 4;
