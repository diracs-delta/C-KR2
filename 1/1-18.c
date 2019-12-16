#include <stdio.h>

#define	MAXCHAR	1000	// maximum characters per line, including trailing \n and \0

int checkLine(char s[]);

/*
   removes trailing blanks and tabs from each line of input
   deletes entirely blank lines
*/
int main() {
	char inputLine[MAXCHAR];

	while(checkLine(inputLine) != -1)
		printf("%s", inputLine);

	return 0;
}

/*
   checks the input line for trailing whitespace/emptiness, then modifies input string accordingly
   returns -1 for EOF
*/
int checkLine(char s[]){
	int c, i, index;
	index = 0;

	while((c = getchar()) != '\n' && c != EOF){
		s[index] = c;
		++index;
	}
	s[index] = '\n';
	s[index + 1] = '\0';

	for(i = index - 1; s[i] == ' ' || s[i] == '\t'; --i){
		s[i] = '\n';
		s[i + 1] = '\0';
	}
	
	if(s[0] == '\n')
		s[0] = '\0';

	if(c == EOF) return -1;
	return 0;
}
