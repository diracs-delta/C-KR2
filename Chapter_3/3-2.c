#include <stdio.h>
#include <string.h>

#define ARRAY_MAX	100

void escape(char s[], char t[]);
void rev_escape(char s[], char t[]);

int main(){
	char input[ARRAY_MAX];
	char output[ARRAY_MAX];
	char c;
	int i;

	for(i = 0; (c = getchar()) != EOF && i < ARRAY_MAX - 1; i++)
		input[i] = c;
	input[i] = '\0';

	printf("\n======================\n");
	printf("Input string");
	printf("\n======================\n");
	printf("%s", input);

	escape(output, input);
	printf("\n======================\n");
	printf("Escaped string");
	printf("\n======================\n");
	printf("%s", output);

	strcpy(input, output);
	rev_escape(output, input);
	printf("\n======================\n");
	printf("Unescaped string");
	printf("\n======================\n");
	printf("%s", output);
}

void escape(char s[], char t[]){
	int i, j;

	for(i = 0, j = 0; t[i] != EOF && j < ARRAY_MAX - 1; i++, j++)
		switch(t[i]){
			case '\t':
				s[j++] = '\\';
				if(j < ARRAY_MAX - 1)
					s[j] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				if(j < ARRAY_MAX - 1)
					s[j] = 'n';
				break;
			default:
				s[j] = t[i];
				break;
		}
	s[j] = '\0';
}

void rev_escape(char s[], char t[]){
	int i, j;

	for(i = 0, j = 0; t[i] != EOF && j < ARRAY_MAX - 1; i++, j++)
		if(t[i] == '\\' && ++i < ARRAY_MAX){
			switch(t[i]){
				case 't':
					s[j] = '\t';
					break;
				case 'n':
					s[j] = '\n';
					break;
				default:
					s[j++] = '\\';
					s[j] = t[i];
					break;
			}
		} else
			s[j] = t[i];
	s[j] = '\0';
}
