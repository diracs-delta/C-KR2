#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CHAR	10

// NOTE: compile with `-lm` flag.

char hex_str[MAX_CHAR];
int stoi(char hex_str[]);

int main(){
	int i, c;

	while((c = getchar()) != EOF && c != '\n' && i < MAX_CHAR - 1)
		hex_str[i++] = c;
	hex_str[i] = '\0';

	stoi(hex_str);
}

int stoi(char hex_str[]){
	// trim optional 0x/0X
	if(hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		for(int i = 0; hex_str[i] != '\0'; i++)
			hex_str[i] = hex_str[i + 2];

	int output = 0;
	int power = 0;
	int digit_nb10 = 0;
	for(int i = strlen(hex_str) - 1; i >= 0; i--){
		digit_nb10 = 0;
		if(hex_str[i] >= '0' && hex_str[i] <= '9')
			digit_nb10 = hex_str[i] - '0';
		else if(hex_str[i] >= 'A' && hex_str[i] <= 'F')
			digit_nb10 = hex_str[i] - 'A' + 10;
		else if(hex_str[i] >= 'a' && hex_str[i] <= 'f')
			digit_nb10 = hex_str[i] - 'a' + 10;
		else{
			printf("ERROR: Unrecognized character in stdin.");
			return -1;
		}
		output += digit_nb10 * pow(16, power++);
	}
	printf("Input in base-10: %d\n", output);
	return 0;
}
