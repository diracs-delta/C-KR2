#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(){
	printf("x = 0653, p = 6, n = 4, y = 0275\n");
	printf("Expected output: 0265\n");
	printf("Output: %o\n", setbits(0653, 6, 4, 0275));

	printf("x = 0474, p = 5, n = 3, y = 0723\n");
	printf("Expected output: 0727\n");
	printf("Output: %o\n", setbits(0474, 5, 3, 0723));

	printf("x = 0777, p = 0, n = 0, y = 0000\n");
	printf("Expected output: 0000\n");
	printf("Output: %o\n", setbits(0777, 0, 0, 0000));
	return 0;
}

/*
 * maybe it could be called bit grafting?
 * 0 1 1 0 0 0 1 1 1 1
 * &
 * 1 1 1 1 1 1 0 1 0 1
 * =
 * 0 1 1 0 0 0 0 1 0 1
*/
unsigned setbits(unsigned x, int p, int n, unsigned y){
	// right shift n-bit field of x, then mask all other bits to 1
	x = (x >> (p + 1 - n)) | (~0 << n);
	// mask last n bits of y to 1
	y = y | ~(~0 << n);
	// return bitwise AND
	return x & y;
}
