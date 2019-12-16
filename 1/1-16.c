#include <stdio.h>

//maximum input line size, including terminating null character \0
#define MAXLINE 10

int returnline(char line[]);
void copy(char to[], char from[]);

/*
   prints longest line from STDIN to STDOUT
*/
int main(){
	int len, max;
	char line[MAXLINE], longest[MAXLINE];
	
	max = 1;
	while((len = returnline(line)) > 1)
		if(len > max){
			max = len;
			copy(longest, line);
		}

	if(max > 1){
		printf("\n===================================================================================\n");

		if (max > MAXLINE){
			printf("ERROR: Longest line exceeds maximum specified character length. Proceeding to output as much as possible.\n");
			printf("Longest line: %s\n", longest);
			printf("Characters in complete line: %d\n", max);
			return -1;
		} else 
			printf("Longest line: %s\n", longest);
	}

	return 0;
}

// returnline: read a line into s and return its length, including \0 (but excludes \n)
int returnline(char s[]){
	int c, i, exceededLimit;
	exceededLimit = 0;

	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if(i < MAXLINE - 1){
			s[i] = c;
		} else 
			exceededLimit = 1;
	}

	if(exceededLimit == 0){
		s[i] = '\0';
	} else {
		s[MAXLINE - 1] = '\0';
	}
	
	return i + 1;
}

// copy: copy 'from' into 'to'; assumes 'to' can store 'from'
void copy(char to[], char from[]){
	int i;
	i = 0;

	while((to[i] = from[i]) != '\0')
		++i;
}
