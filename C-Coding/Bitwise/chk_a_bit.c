#include <stdio.h>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");

    printf("\n");
}

int main () {

	unsigned int num;
	int pos;
	printf("Enter a number\n");
	scanf("%d", &num);
	
	bin(num);

	printf("\nEnter a position to check\n");
	scanf("%d", &pos);

	if (num & (1 << pos))
		printf("Set\n");
	else
		printf("Not-Set\n");

	return 0;
}
