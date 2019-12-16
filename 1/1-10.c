#include <stdio.h>
/*
   replaces all backslashes and tabs with their
   corresponding escape sequences

   doesn't work with "new" backspace that deletes
   characters. seems to be limitted to old UNIX
   terminal emulators.
*/

main(){
	int c;
	while((c = getchar()) != EOF){
		if(c != '\\' && c!= '\b' && c!= '\t')
			putchar(c);
		if(c == '\\'){
			putchar('\\');
			putchar('\\');
		}
		if(c == '\b'){
			putchar('\\');
			putchar('b');
		}
		if(c == '\t'){
			putchar('\\');
			putchar('t');
		}
	}
}
