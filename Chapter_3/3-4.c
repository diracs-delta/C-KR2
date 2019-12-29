#include <stdio.h>
#include <string.h>

#define ARRAY_MAX	100
#define INPUT_NO	5

void itoa(int n, char s[]);
char *strrev(char *str);

int main(){
	int input[INPUT_NO] = {24, 59, 31, 600, 0x80000000};
	int i;
	char output[ARRAY_MAX];

	for(i = 0; i < INPUT_NO; i++){
		printf("Input: %d\n", input[i]);
		itoa(input[i], output);
		printf("Output: %s\n", output);
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

/*
 * the original `itoa()` function fails because a signed integer under the two's
 * complement system cannot simply be inverted with a negative sign due to a
 * lack of memory. under the two's complement system, the largest possible
 * negative number is 0x80000000 (100...000 = -2,147,483,648), whilst the the
 * largest possible positive number is 0x7FFFFFFF (011...111 = +2,147,483,637).
 * naively taking the negative (two's complement) of 0x80000000 actually results
 * in the return of the same number 0x80000000. hence, n % 10 executed first in
 * the do-while loop results in -8 in decimal, which results in the character
 * '(' = 40 = '0' - 8.
 *
 * to rememdy this, we a new _unsigned_ int m to store the value of n, whose
 * maximum is now 0xFFFFFFFF (111...111 = +4,294,967,295)
 */

void itoa(int n, char s[])
{
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
	s[i] = '\0';

	strrev(s);
}
