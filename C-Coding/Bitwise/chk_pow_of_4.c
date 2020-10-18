#include <stdio.h>

int main () {
	unsigned int num;
	printf("Enter any number to check pow of '4'\n");
	scanf("%d", &num);
	if ((num != 0) && ((num & (num -1)) == 0) && !(num & 0xAAAAAAAA))
		printf("%d: pow of 4\n", num);
	else
		printf("%d: Not pow of 4\n", num);

	return 0;
}
