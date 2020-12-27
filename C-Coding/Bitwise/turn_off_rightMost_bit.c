#include <stdio.h>
#include <stdlib.h>

#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS)

unsigned int turn_off_rightMost_Bit(unsigned int num)
{
	return num & (num - 1);
}

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
}

int main () {
	int num;

	printf("Enter num for turning off right most bit\n");
	scanf("%d", &num);

	unsigned int temp = turn_off_rightMost_Bit(num);
	printf("\n");
	bin(num);
	printf("\nTurning off right most bit\n");
	bin(temp);
	printf("\n");

	return 0;
}
