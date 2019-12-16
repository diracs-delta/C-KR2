#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(){
	printf("x = 0653, p = 7, n = 3\n");
	printf("Expected output: 513\n");
	printf("Output: %o\n", invert(0653, 7, 3));
	printf("--------------------------------------\n");
	printf("x = 0474, p = 5, n = 5\n");
	printf("Expected output: 402\n");
	printf("Output: %o\n", invert(0474, 5, 5));
	printf("--------------------------------------\n");
	printf("x = 01126, p = 9, n = 6\n");
	printf("Expected output: 0646\n");
	printf("Output: %o\n", invert(01126, 9, 6));
	printf("--------------------------------------\n");
	return 0;
}

/*
 * i suddenly realized the utility of XOR in a random stroke of wisdom after
 * reading Kernighan's wikipedia page.
 *
 * XOR behaves as NOT when the complementary value is 1,
 * and behaves as OR when the complementary value is 0.
*/
unsigned invert(unsigned x, int p, int n){
	return x ^ ((~(~0 << n)) << (p + 1 - n));
}
