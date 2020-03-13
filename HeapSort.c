/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include "Sort.h"

static void swap(int* array, int a, int b);
static void max_heapify(int* array, int length, int node);

void sort(int* array, size_t length)
{
	for(int i = length/2 - 1; i >= 0; i--) {
		max_heapify(array, length, i);
	}
}

static void max_heapify(int* array, int length, int node) {
	int left = 2 * node;
	int right = 2 * node + 1;
	int largest = node;
	if(left < length && array[left] > array[node]) {
		largest = left;
	}
	if(right < length && array[right] > array[largest]) {
		largest = right;
	}
	if(node != largest) {
		swap(array, node, largest);
		max_heapify(array, length, largest);
	}
}

// a, b = indices
static void swap(int* array, int a, int b) {
	int tmp = array[b];
	array[b] = array[a];
	array[a] = tmp;
}