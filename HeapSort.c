/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "Sort.h"

static void swap(int* array, int a, int b);
static void max_heapify(int* array, int length, int node);

void sort(int* array, size_t length)
{
	// build max heap
	for(int i = floor(length/2) - 1; i >= 0; i--) {
		max_heapify(array, length, i);
	}
	for(int i = length - 1; i > 0; i--) {
		swap(array, i, 0);
		length--;
		max_heapify(array, length, 0);
	}
}

static void max_heapify(int* array, int length, int node) {
	int left = 2 * node + 1;
	int right = 2 * node + 2;
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
