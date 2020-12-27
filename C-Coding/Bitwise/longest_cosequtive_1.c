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
	int count = 0;
	printf("Enter number\n");
	scanf("%d", &num);
	bin(num);
	while (num) {
		num &= (num << 1);
		count++;
	}

	printf("Longest 1's: %d\n", count);
}
