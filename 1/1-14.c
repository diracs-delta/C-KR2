#include <stdio.h>

// specifies maximum number of characters stored
#define	MAXCHAR	100

/*
   counts all characters and their frequencies
   then prints a histogram
*/

int main() {
	int c, counted, counter, i;
	int chars[MAXCHAR], charfreq[MAXCHAR];
	
	counted = counter = 0;
	for(i = 0; i < MAXCHAR; ++i)
		charfreq[i] = chars[i] = 0;

	while((c = getchar()) != EOF){
		counted = 0;
		for(i = 0; i < counter; ++i){
			if(c == chars[i]){
				++charfreq[i];
				counted = 1;
			}
		}

		if(counted != 1){
			chars[counter] = c;
			charfreq[counter] = 1;
			++counter;
		}
	}

	// histogram

	int height;
	height = 0;

	for(i = 0; i < counter; ++i)
		if(charfreq[i] > height)
			height = charfreq[i];

	while(height != 0){
		for(i = 0; i < counter; ++i){
			if(charfreq[i] >= height)
				printf(" \u2588 ");
			else
				printf("   ");
		}
		printf("\n");
		--height;
	}

	for(i = 0; i < counter; ++i)
		printf("-|-");
	printf("\n");

	for(int i = 0; i < counter; ++i){
		printf(" ");

		if(chars[i] == '\n')
			printf("\\n");
		else if(chars[i] == '\t')
			printf("\\t");
		else{
			putchar(chars[i]);
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
