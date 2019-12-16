#include <stdio.h>

#define	MINCHAR	20	// minimum character limit to print to stdout
#define	MAXCHAR	1000	// maximum character length of each line

int getLine(char s[]);

/*
   prints stdin lines longer than MAXCHAR to stdout
*/
int main(){
	int lineLength;
	char currentLine[MAXCHAR];

	while((lineLength = getLine(currentLine)) != -1)
		if(lineLength > MINCHAR)
			printf("%d -- %s\n", lineLength, currentLine);

	return 0;
}

// returns length of each line
int getLine(char s[]){
	int c, length;
	length = 0;
	while((c = getchar()) != '\n'){
		if(c == EOF)
			return -1;
		s[length] = c;
		++length;
	}
	s[length] = '\0';
	return length;
}
