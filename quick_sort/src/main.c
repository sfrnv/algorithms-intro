#include <stdio.h>
#include "quicksort.h"

void printarr(int *, int);

int main(int argc, char *argv[]) {
	int arr[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int length = sizeof(arr) / sizeof((arr)[0]);
	printarr(arr, length);
	quicksort(arr, 0, length - 1);
	printarr(arr, length);
	return 0;
}

void printarr(int *arr, int length) {
	printf("{");
	for (int i = 0; i < length; ++i)
	{
		printf("%d, ", arr[i]);
	}
	printf("\b\b}\n");
}