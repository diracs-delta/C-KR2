#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(){
	printf("x = 0653, n = 2\n");
	printf("Expected output: 653\n");
	printf("Output: %o\n", rightrot(0653, 1));
	printf("--------------------------------------\n");
	return 0;
}

/*
 * learned that right bitwise shift >> has undefined behavior for signed
 * integers, which took me about an hour. then i learned that printf requires
 * the `l` modifier for proper long output.
*/
unsigned rightrot(unsigned x, int n){
	while(n-- > 0)
		if(x & 01)
			x = ((x >> 1) | ~(~0U >> 1));
		else
			x = x >> 1;
	printf("%u\n", ~(~0 >> 1));
	printf("%u\n", ~(~0U >> 1));
	printf("%u\n", ~(~0L >> 1));
	printf("%u\n", ~(~0UL >> 1));
	printf("%lu\n", ~(~0UL >> 1));
	return x;
}
