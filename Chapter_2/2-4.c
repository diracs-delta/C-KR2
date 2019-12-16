#include <stdio.h>

#define MAX_CHAR	10
#define TRUE		1
#define FALSE		0

void squeeze(char input[], char delete[]);

int main(){
	char input[MAX_CHAR];
	char delete[MAX_CHAR] = "aeiou";
	int i, c;
	i = c = 0;
	while((c = getchar()) != EOF && c != '\n' && i != MAX_CHAR - 1)
		input[i++] = c;
	input[i] = '\0';

	squeeze(input, delete);
	return 0;
}

void squeeze(char input[], char delete[]){
	int i, j, match;
	for(i = j = 0; input[i] != '\0'; i++){
		match = FALSE;
		for(int k = 0; delete[k] != '\0'; k++)
			if(input[i] == delete[k])
				match = TRUE;
		if(match != TRUE)
			input[j++] = input[i];
	}
	input[j] = '\0';

	for(i = 0; input[i] != '\0'; i++)
		putchar(input[i]);
}
