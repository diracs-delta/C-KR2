#include <stdio.h>
#include <string.h>

#define ARRAY_MAX	19
#define INPUT_NO	5

void itoa(int n, char s[], int pad);
char *strrev(char *str);

int main(){
	int input[INPUT_NO] = {24, 59, 31, 600, 0x80000000};
	int input_pad[INPUT_NO] = {20,18,16,14,12};
	int i;
	char output[ARRAY_MAX];

	for(i = 0; i < INPUT_NO; i++){
		printf("Input: %d with %d padding\n", input[i], input_pad[i]);
		itoa(input[i], output, input_pad[i]);
		printf("Output: |%s|, length = %d\n", output, strlen(output));
	}
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

void itoa(int n, char s[], int pad)
{
	// check to see if padding exceeds maximum char array size, including
	// the null terminator.
	if(pad > ARRAY_MAX - 1){
		printf("ERROR: Padding cannot exceed maximum array size.\n");
		char error_msg[ARRAY_MAX] = "ERROR";
		strcpy(s, error_msg);
		return;
	}

	int i, sign;
	unsigned int m;

	if((sign = n) < 0)
		m = -n;
	else
		m = n;
	i = 0;
	do {
		s[i++] = m % 10 + '0';
	} while ((m /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';

	// then add all the spaces on the right prior to strrev() call
	while(i < pad)
		s[i++] = ' ';
	s[i] = '\0';

	strrev(s);
}
