#include <stdio.h>

// define maximum characters per line, including trailing \n and \0
#define	MAXCHAR	1000

int reverse(char s[]);

int main() {
	char inputLine[MAXCHAR];
	while(reverse(inputLine) != -1)
		printf("%s", inputLine);
	return 0;
}

// reads lines from stdin and reverses the character order, storing output in its string parameter
int reverse(char s[]){
	int c, i, j;
	char temp;

	for(i = 0; (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	for(j = 0; j < i && i-j-1 >= j; ++j){
		temp = s[j];
		s[j] = s[i-j-1];
		s[i-j-1] = temp;
	}
	
	if(c == EOF){
		s[i] = '\0';
		return -1;
	}
	
	s[i] = '\n';
	s[i+1] = '\0';
	return 0;
}
