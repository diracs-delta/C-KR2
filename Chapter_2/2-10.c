#include <stdio.h>

#define MAX_CHAR	10

char lower(char c);

int main(){
	char input[3][MAX_CHAR] = {"FUNNNnn", "AsDfGhJkL", "OWObulGE"};
	for(int i = 0; i < 3; i++){
		printf("Input: %s\n", input[i]);
		printf("Output: ");
		for(int j = 0; input[i][j] != '\0'; j++)
			putchar(lower(input[i][j]));
		putchar('\n');
	}
	return 0;
}

char lower(char c){
	return ((c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c);
}
