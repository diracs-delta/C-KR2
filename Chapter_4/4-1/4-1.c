#include <stdio.h>
#include <string.h>

#define MAXLINE		1000
#define BOLD_TERMCODE	"\e[1m"
#define COLOR_TERMCODE	"\e[93m"
#define RESET_TERMCODE	"\e[0m"

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);
void pretty(char line[], int index);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;
	int index, rev_index, j;

	while (get_line(line, MAXLINE) > 0)
		if ((index = strindex(line, pattern)) >= 0) {
			rev_index = strrindex(line, pattern);
			if(rev_index != index){
				printf("Differing output\n");
				pretty(line, index);
				pretty(line, rev_index);
			} else {
				pretty(line, index);
			}
		}
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if ( c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int strrindex(char s[], char t[])
{
	int i, j, k;
	for (i = strlen(s) - 1; i >= 0; i--){
		for (j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; j--, k--)
			;
		// k will be -1 if all of `t` is contained within `s`
		if (k < 0)
			return i - strlen(t) + 1;
	}
	return -1;
}

/*
 * pretty(): formats `line` by bolding and coloring `pattern` found at `index`.
 */
void pretty(char line[], int index)
{
	int j;

	printf("Index %d:\t", index);
	for(j = 0; j < index; j++)
	putchar(line[j]); printf("%s", BOLD_TERMCODE);
	printf("%s", COLOR_TERMCODE);
	for(j; j < index + strlen(pattern); j++)
		putchar(line[j]);
	printf("%s", RESET_TERMCODE);
	for(j; line[j] != '\0'; j++)
		putchar(line[j]);
	if(line[strlen(line) - 1] != '\n')
		putchar('\n');
}
