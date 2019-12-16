#include <stdio.h>
/* 
   print fahrenheit -> celsius table
*/

float converter(float fahr);

int main() {
	float fahr;
	int lower, upper, step;
	lower=0;
	upper=300;
	step=20;
	fahr=lower;

	printf("%3s %6s\n","F","C");

	while(fahr<=upper){
		printf("%3.0f %6.1f\n", fahr, converter(fahr));
		fahr=fahr+step;
	}

	return 0;
}

float converter(float fahr){
	return (5.0/9.0) * (fahr-32.0);
}
