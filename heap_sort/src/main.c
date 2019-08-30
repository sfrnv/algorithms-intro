#include <stdio.h>
#include "heap.h"

void printarr(int *, int);

int main(int argc, char *argv[]) {
	// int arr[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int length = sizeof(arr) / sizeof((arr)[0]) - 1; // -1 to exclude first dummy element

	printarr(arr, length);
	struct heap *pt = build_max_heap(arr, length);
	printarr(pt->data, length);

	pt = build_empty_heap(32);
	for (int i = 1; i < 21; ++i)
	{
		insert(pt, i);
	}
	printarr(pt->data, 20);
	return 0;
}

void printarr(int *arr, int length) {
	printf("{");
	for (int i = 0; i < length; ++i)
	{
		printf("%d, ", arr[i+1]);
	}
	printf("\b\b}\n");
}