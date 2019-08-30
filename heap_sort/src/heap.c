#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/**
 * parent: calculate parent i in heap
 * @param  i one-based i in heap
 * @return   one-based parent i in heap
 */
int parent(int i) {
	return i >> 1;
}

/**
 * left: calculate left child i in heap
 * @param  i one-based i in heap
 * @return   one-based left child i in heap
 */
int left(int i) {
	return i << 1;
}

/**
 * right: calculate right child i in heap
 * @param  i one-based i in heap
 * @return       one-based right child i in heap
 */
int right(int i) {
	return (i << 1) + 1;
}

/**
 * [max_heapify description]
 * @param pt [description]
 * @param i  [description]
 */
void max_heapify(struct heap *pt, int i) {
	if (i <= 0)
		return;
	int l = left(i);
	int r = right(i);
	int *arr = pt->data;
	int max;
	if (l <= pt->size && arr[l] > arr[i])
		max = l;
	else
		max = i;
	if (r <= pt->size && arr[r] > arr[max])
		max = r;
	if (max != i) {
		int tmp = arr[i];
		arr[i] = arr[max];
		arr[max] = tmp;
		max_heapify(pt, max);
	}

}

/**
 * build_max_heap: build max-heap contained
 * @param  arr    input data array
 * @param  length length of data array
 * @return        pointer to builded heap
 */
struct heap *build_max_heap(int *arr, int length) {
	struct heap *pt = (struct heap *) malloc(sizeof(struct heap));
	pt->size = length;
	pt->length = length;
	pt->data = arr;
	for (int i = parent(pt->size); i >= 1; --i)
	{
		max_heapify(pt, i);
	}
	return pt;
}