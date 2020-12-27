#include <stdio.h>
#include <stdbool.h>

int main () {

	int a = -5;
	int b = -1;
	
	if((a ^ b) < 0)
		printf("Have opposite sign\n");
	else
		printf("Have same sign\n");

	return 0;
}
