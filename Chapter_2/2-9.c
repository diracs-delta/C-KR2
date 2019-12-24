#include <stdio.h>

int bitcount(unsigned x);

int main(){
	printf("Input: 07777\n");
	printf("Expected output: 12\n");
	printf("Output: %d\n", bitcount(07777));
	printf("Input: 03614\n");
	printf("Expected output: 6\n");
	printf("Output: %d\n", bitcount(03614));
	printf("Input: 05632\n");
	printf("Expected output: 7\n");
	printf("Output: %d\n", bitcount(05632));
}

int bitcount(unsigned x){
	int b;
	for(b = 0; x != 0; x >>= 1){
		x &= (x - 1);
		b++;
	}
	return b;
}
