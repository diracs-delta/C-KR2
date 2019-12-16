#include <stdio.h>

#define TABWIDTH	8	// specifies the desired number of spaces per tab
#define	MAXCHAR		1000	// defines maximum characters per line

int calcSpaces(int a);

/*
   replaces all tabs in the input with the number
   of spaces necessary to generate a visually identical
   copy.

   this isn't just replacing each tab with TABWIDTH spaces.
   consider the following:

   foo	bar

   there is a tab between the two, yet it only takes up 2 space
   since 'bar' is placed on the 9th block, whereas my default
   tab is set to 8 blocks in width.
*/
int main(){
	int c, i, position;
	char line[MAXCHAR];
	position = 0;

	while((c = getchar()) != EOF){
		if(c != '\n'){
			if(c == '\t')
				for(i = 0; i < calcSpaces(position); ++i){
					putchar(' ');
					++position;
				}
			else{
				putchar(c);
				++position;
			}
		}else{
			putchar(c);
			position = 0;
		}
	}
}

/*
   calcSpaces -- finds the minimum number of spaces to achieve
   a multiple of TABWIDTH.
*/
int calcSpaces(int a){
	int spaces, i;
	i = 0;

	while(i * TABWIDTH < a)
		i++;
	if((spaces = i * TABWIDTH - a) != 0)
		return spaces;
	else 
		return 8;
}
