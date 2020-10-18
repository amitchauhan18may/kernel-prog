#include <stdio.h>

int main () {

	int num;
	int  m = 1;
	printf("Please enter the number\n");
	scanf("%d", &num);

	while ((num & m) == 0) {
		num ^= m;
		m <<= 1;
	}

	num ^= m;

	printf("subtracted_1: %d\n", num);
}
