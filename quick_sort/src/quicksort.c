/**
 * swap: exchanges two elements in array
 * @param arr pointer to array for swapping
 * @param i   index of first element
 * @param j   index of second element
 */
void swap(int *arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/**
 * le_partition: last element partition scheme
 * @param  arr   pointer to array for partitioning
 * @param  left  left element in the array for partitioning
 * @param  right right element in the array for partitioning
 * @return       pivot position in the array
 */
int le_partition(int *arr, int left, int right) {
	int x = arr[right];
	int i = left - 1;
	for (int j = left; j < right; ++j)
	{
		if(arr[j] <= x) {
			swap(arr, ++i, j);
		}
	}
	swap(arr, ++i, right);
	return i;
}

/**
 * me_partition: middle element partition scheme
 * @param  arr   pointer to array for partitioning
 * @param  left  left element in the array for partitioning
 * @param  right right element in the array for partitioning
 * @return       pivot position in the array
 */
int me_partition(int *arr, int left, int right) {
	swap(arr, left, (left + right) / 2); // move pivot element to arr[O]
	int last = left;
	for (int i = left + 1; i <= right; ++i) { // partition
		if (arr[i] < arr[left])
			swap(arr, ++last, i);
	}
	swap(arr, left, last); // restore pivot element
	return last;
}

/**
 * quicksort: sort elements in array in increasing order
 * @param arr   pointer to array for sort
 * @param left  left element in the array to sort
 * @param right right element in the array to sort
 */
void quicksort(int *arr, int left, int right) {
	if (left < right) {
		int q = le_partition(arr, left, right);
		quicksort(arr, left, q - 1);
		quicksort(arr, q + 1, right);
	}
}