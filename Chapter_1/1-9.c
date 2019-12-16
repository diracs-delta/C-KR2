#include <stdio.h>
/*
   replaces redundant spaces with one space
   	e.g. "hello       world" => "hello world"
*/

main(){
	int c, cbefore;
	cbefore=getchar();
	if (cbefore != ' ')
		putchar(cbefore);

	while ((c = getchar()) != EOF){
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if(cbefore != ' ')
				putchar(c);
		cbefore=c;
	}
}
