#include <stdio.h>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");

    printf("\n");
}

unsigned int rotate_left(unsigned int num, int rotate) {
	printf("Rotating left %d:Times\n", rotate);
	return (num << rotate) | (num >> (32 - rotate));
}

unsigned int rotate_right(unsigned int num, int rotate) {
	printf("Rotating left %d:Times\n", rotate);
	return (num >> rotate) | (num << (32 - rotate));
}

int main () {

	unsigned int num;
	int rotate;

	printf("Enter any number\n");
	scanf("%d", &num);
	
	bin(num);
	printf("Enter any number for rotate\n");
	scanf("%d", &rotate);
	if (rotate > 32) {
		printf("Can not give rotation more than 32\n");
	}

	unsigned int get_val = rotate_right(num, rotate);
	bin(get_val);

	return 0;
}
