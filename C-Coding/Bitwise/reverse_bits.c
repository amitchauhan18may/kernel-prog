#include <stdio.h>
#include <stdlib.h>

#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS)

unsigned int ReverseTheBits(unsigned int num)
{
	unsigned int rev_bit_num = 0;
	int i;

	for (i = 0; i < INT_BITS; i++){
		if (num & (1 << i))
			rev_bit_num |= (1 << (INT_BITS - 1 - i));
	}

	return rev_bit_num;
}

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
}

int main () {
	unsigned int temp = ReverseTheBits(10);
	printf("\n");
	bin(10);
	printf("\n");
	bin(temp);
	printf("\n");

	return 0;
}
