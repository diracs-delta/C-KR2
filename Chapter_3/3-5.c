// if you are using GCC, remember to compile with the `-lm` flag.
#include <stdio.h>
#include <math.h>
#include <string.h>

#define INPUT_NO	5
#define ARRAY_MAX	100

/* inclusively define the continuous range of ASCII characters to represent
 * digits outside 0-9 for bases larger than 10. the default values use A-Z,
 * allowing a maximum of base 36.
 */
#define ASCII_MIN	65
#define ASCII_MAX	90

char *strrev(char *str);
void itob(int n, char s[], int b);

int main(){
	char output[ARRAY_MAX];
	int input[INPUT_NO] = {101,-60342,967529,-2395,57630};
	int base[INPUT_NO] = {10, 8, 16, 2, 27};

	for(int i = 0; i < INPUT_NO; i++){
		printf("Input: %d in decimal\n", input[i]);
		itob(input[i], output, base[i]);
		printf("Output: %s in base %d\n", output, base[i]);
	}
	return 0;
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

void itob(int n, char s[], int b)
{
	if((ASCII_MAX - ASCII_MIN) + 11 < b){
		printf("ERROR: ASCII range is too small.\n");
		return;
	}

	int sign, remainder, divisor, weight, i = 0;
	unsigned int m;
	char digit;
	if((sign = n) < 0)
		m = -n;
	else
		m = n;
	i = 0;

	do{
		divisor = pow(b, i + 1);
		weight = pow(b, i);

		// determine remainder in terms of b^i
		remainder = (m % divisor) / weight;

		// determine corresponding ASCII digit
		if(remainder <= 9)
			digit = remainder + '0';
		else
			digit = remainder + ASCII_MIN - 10;
		s[i++] = digit;

	// substract remainder * weight, repeat until finished
	}while((m -= remainder * weight) > 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	strrev(s);
}
