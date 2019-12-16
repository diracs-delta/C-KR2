#include <stdio.h>

#define MAX_CHAR	10
#define TRUE		1
#define FALSE		0

int squeeze(char input[], char detect[]);

int main(){
	char input[MAX_CHAR];
	char detect[MAX_CHAR] = "aeiou";
	int i, c;
	i = c = 0;
	while((c = getchar()) != EOF && c != '\n' && i != MAX_CHAR - 1)
		input[i++] = c;
	input[i] = '\0';

	printf("First input: %d\n", squeeze(input, detect));
	return 0;
}

int squeeze(char input[], char detect[]){
	int i, match;
	for(i = 0; input[i] != '\0'; i++)
		for(int k = 0; detect[k] != '\0'; k++)
			if(input[i] == detect[k])
				return i;
	return -1;
}
