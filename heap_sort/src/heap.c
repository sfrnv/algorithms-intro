#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
 * @return   one-based right child i in heap
 */
int right(int i) {
	return (i << 1) + 1;
}

/**
 * swap: swaps two heap elements
 * @param pt pointer to heap
 * @param i  one-based index of first element
 * @param j  one-based index of second element
 */
void swap(struct heap *pt, int i, int j) {
	int tmp = pt->data[i];
	pt->data[i] = pt->data[j];
	pt->data[j] = tmp;
	return;
}

/**
 * max_heapify: 
 * @param pt pointer to heap
 * @param i  one-based index of element
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
		swap(pt, i, max);
		max_heapify(pt, max);
	}

}

/**
 * build_max_heap: constructs max-heap container
 * @param  arr  input data array
 * @param  size heap size
 * @return      pointer to new heap
 */
struct heap *build_max_heap(int *arr, int size) {
	struct heap *pt = (struct heap *) malloc(sizeof(struct heap));
	pt->size = size;
	pt->length = size;
	pt->data = arr;
	for (int i = parent(pt->size); i >= 1; --i)
	{
		max_heapify(pt, i);
	}
	return pt;
}

/**
 * build_empty_heap: constructs empty heap container
 * @param  length size of undelying array
 * @return        pointer to new heap
 */
struct heap *build_empty_heap(int length) {
	struct heap *pt = (struct heap *) malloc(sizeof(struct heap));
	pt->size = 0;
	pt->length = length;
	pt->data = (int *) malloc(sizeof(int) * length);
	return pt;
}

/**
 * peek: retrieves, but does not remove, the head of this heap
 * @param  pt pointer to heap
 * @return    the head of this heap
 */
int peek(struct heap *pt) {
	if (pt == NULL || pt->size < 2)
		return -1; // error
	return pt->data[1];
}

/**
 * poll: retrieves and removes the head of this heap
 * @param  pt pointer to heap
 * @return    the head of this heap
 */
int poll(struct heap *pt) {
	if (pt == NULL || pt->size < 2)
		return -1; // error
	int max = pt->data[1];
	pt->data[1] = pt->data[pt->size--];
	max_heapify(pt, 1);
	return max;
}

/**
 * increase_key: replaces value of i'th element in heap with new value, if new > old
 * @param pt  pointer to heap
 * @param i   one-based index of element
 * @param new new value of element
 */
void increase_key(struct heap *pt, int i, int new) {
	if (pt == NULL)
		return; // error: NULL pointer
	if (pt->size < 1)
		return; // error: empty heap
	if (i < 1 || i > pt->size)
		return; // error: index is out of borders
	if (new < pt->data[i])
		return; // error: new key is smaller than current key
	pt->data[i] = new;
	while (i > 1 && pt->data[parent(i)] < pt->data[i]) {
		swap(pt, i, parent(i));
		i = parent(i);
	}
}

/**
 * insert: inserts the specified element into this heap
 * @param pt  pointer to heap
 * @param new the element to add
 */
void insert(struct heap *pt, int new) {
	pt->data[++pt->size] = INT_MIN;
	increase_key(pt, pt->size, new);
}