#include <stdio.h>

int main () {
	unsigned int num;
	printf("Enter any number to check pow of '2'\n");
	scanf("%d", &num);
	if (num & (num -1))
		printf("%d: Not pow of 2\n", num);
	else
		printf("%d: pow of 2\n", num);

	return 0;
}
