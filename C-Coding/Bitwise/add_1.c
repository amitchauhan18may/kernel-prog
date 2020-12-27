#include <stdio.h>

int main () {

	int num;
	int  m = 1;
	printf("Please enter the number\n");
	scanf("%d", &num);

	while (num & m) {
		num ^= m;
		m <<= 1;
	}

	num ^= m;

	printf("Added_1: %d\n", num);
}
