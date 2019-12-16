#include <stdio.h>

#define	IN	1
#define OUT	0
#define LENGTH	99
/*
   will print a vertical histogram of the word lengths
   in input. this assumes the longest word possible is
   the LENGTH constant specified above. this is limitted
   by the text formatting of the histogram, and hence
   LENGTH is limitted at 99 characters.

   in addition, words cannot be 0 characters long.
*/

int main(){
	int c, i, state, nword;
	int ndigit[LENGTH];
	for(i = 0; i < LENGTH; ++i)
		ndigit[i] = 0;
	state = OUT;
	nword = 0;

	while((c = getchar()) != EOF){
		if(c != '\n' && c != '\t' && c != ' '){
			state = IN;
			++nword;

			while(state == IN){
				c = getchar();
				if(c != EOF && c != '\n' && c != '\t' && c != ' ')
					++nword;
				else{
					++ndigit[nword-1];
					nword = 0;
					state = OUT;
				}
			}
		} else
			state = OUT;
	}
	
	/* histogram */
	
	int width, height;
	width = height = 0;

	for(i = 0; i < LENGTH; ++i){
		if(ndigit[i] != 0)
			width = i+1;
		if(ndigit[i] > height)
			height = ndigit[i];
		//printf("There are %d %d-length characters\n", ndigit[i], i+1);
	}

	while(height != 0){
		for(i = 0; i < width; ++i){
			if(ndigit[i] >= height)
				printf(" \u2588 ");
			else
				printf("   ");
		}
		printf("\n");
		--height;
	}
	for(i = 0; i < width; ++i)
		printf("-|-");
	printf("\n");
	for(i = 0; i < width; ++i){
		printf(" ");
		printf("%-2d",i+1);
	}
	printf("\n");

	return 0;
}
