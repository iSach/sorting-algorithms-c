/* ========================================================================= *
 * QuickSort
 * Implementation of the QuickSort algorithm.
 * ========================================================================= */

#include "Sort.h"
#include <stddef.h>
#include <stdlib.h>

static void quick_sort(int *array, int p, int r);
static int partition(int *array, int p, int r);
static int random_partition(int *array, int p, int r);
static void swap(int *array, int a, int b);


void sort(int *array, size_t length) { quick_sort(array, 0, length - 1); }

static void quick_sort(int *array, int p, int r) {
  if (p < r) {
    int q = random_partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
  }
}

static int random_partition(int *array, int p, int r)
{
	int random_pivot = (rand() % (r-p)) + p;
	swap(array, random_pivot, r);
	return partition(array, p, r);
}

static int partition(int *array, int p, int r) {
  int pivot = array[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (array[j] <= pivot) {
      i++;
  	  if (j != i)
      	swap(array, i, j);
    }
  }
  if (r != i + 1)
    swap(array, i + 1, r);

  return i + 1;
}

// a, b = indices
static void swap(int *array, int a, int b) {
  int tmp = array[b];
  array[b] = array[a];
  array[a] = tmp;
}
