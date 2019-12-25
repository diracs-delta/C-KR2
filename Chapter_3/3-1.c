#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX	1000000

int binsearch(int x, int v[], int n);
int orig_binsearch(int x, int v[], int n);

int main(){
	// generate sorted array
	int sorted[ARRAY_MAX];
	sorted[0] = 0;
	for(int i = 1; i < ARRAY_MAX; i++)
		sorted[i] = (2 * i) + ((rand() % 3) - 1);
	/*
	printf("Index\tValue\n");
	for(int i = 0; i < ARRAY_MAX; i++)
		printf("%d\t%d\n", i, sorted[i]);
	*/

	// test times
	int inputs[5] = {3993, 1034, 9932, 4020, 7777};
	clock_t t;
	double time;

	printf("-------------------------------\n");
	printf("Original binary search function\n");
	printf("-------------------------------\n");
	printf("Input\tOutput\n");
	t = clock();
	for(int i = 0; i < 5; i++)
		printf("%d\t%d\n", inputs[i], orig_binsearch(inputs[i], sorted, ARRAY_MAX));
	time = (clock() - t)/((double) CLOCKS_PER_SEC);
	printf("Time: %e\n", time);

	printf("-------------------------------\n");
	printf("Improved binary search function\n");
	printf("-------------------------------\n");
	printf("Input\tOutput\n");
	t = clock();
	for(int i = 0; i < 5; i++)
		printf("%d\t%d\n", inputs[i], binsearch(inputs[i], sorted, ARRAY_MAX));
	time = (clock() - t)/((double) CLOCKS_PER_SEC);
	printf("Time: %e\n", time);
}

int binsearch(int x, int v[], int n){
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if(v[low] == x)
		return low;
	else if(v[high] == x)
		return high;
	else
		return -1;
}

int orig_binsearch(int x, int v[], int n){
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
