#include <stdio.h>

int main () {
	int num;
	printf("Enter the number to multiply with '3.5'\n");
	scanf("%d", &num);

	printf("%d X 3.5 = ", num);
	
	num = (num << 1) + num + (num >> 1);

	printf("%d\n", num);


	return 0;
}
