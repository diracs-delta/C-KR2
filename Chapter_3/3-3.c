#include <stdio.h>
#include <string.h>

#define ARRAY_MAX	100
#define INPUTS_NO	6

void expand(char s1[], char s2[]);

int main(){
	char input[INPUTS_NO][ARRAY_MAX]
		= {"a-z", "a-b-c0-9", "z-a-z", "0-9", "-a-z-", "A-Q-Z"};
	char output[ARRAY_MAX];
	for(int i = 0; i < INPUTS_NO; i++){
		printf("Input: %s\n", input[i]);
		expand(input[i], output);
		printf("Output: %s\n", output);
	}
}

void expand(char s1[], char s2[]){
	int i, c;
	int j = 0;

	// copy first char no matter what
	s2[j++] = s1[0];

	// scan over s1, excluding null terminator
	// then, expand hyphen to include all chars bounded by the preceding and
	// succeeding characters
	for(i = 1; i < strlen(s1); i++)
		if(s1[i] == '-' && i < ARRAY_MAX - 2 && s1[i - 1] < s1[i + 1])
			for(c = s1[i - 1] + 1; c < s1[i + 1]; c++)
				if(j < ARRAY_MAX - 1)
					s2[j++] = c;
				else
					return;
		else
			if(j < ARRAY_MAX - 1)
				s2[j++] = s1[i];
			else
				return;

	// finally, add null terminator
	s2[j] = s1[i];
}
