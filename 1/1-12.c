#include <stdio.h>

#define	IN	1
#define OUT	0	
/*
   prints input one word per line
*/

main(){
	int c, state;
	state = OUT;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			if (state == IN){
				putchar('\n');
				state = OUT;
			}
		} else {
			putchar(c);
			state = IN;
		}
	}
}
