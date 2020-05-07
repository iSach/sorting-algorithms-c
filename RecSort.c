#include <stdlib.h>
#include <stddef.h>
#include "Sort.h"

void swap(int *array, int a, int b);
static void rec_sort(int* array, int p, int r);
static int place(int* array, int p, int r, int k);
static void merge(int* array, int p, int q, int r);
static int random_place(int *array, int p, int r);

void sort(int* array, size_t length) {
	rec_sort(array, 0, length - 1);
}

static void rec_sort(int* array, int p, int r) {
	if(p < r) {
		int q = random_place(array, p, r);
		rec_sort(array, p, q - 1);
		rec_sort(array, q + 1, r);
		merge(array, p, q, r);
	}
}

static int random_place(int *array, int p, int r) {
	int random_pivot = (rand() % (r-p)) + p;
	swap(array, random_pivot, r);
	return place(array, p, r, r);
}

static int place(int* array, int p, int r, int k) {
	int m = 0;
	for(int i = p; i <= r; i++)
		if(array[i] < array[k])
			m++;
	int l = m + p;
	swap(array, k, l);
	return l;
}

static void merge(int* array, int p, int q, int r) {
	int left_size = q - p;
	int right_size = r - q;
	int left[left_size], right[right_size];

	for(int i = 0; i < left_size; i++)
		left[i] = array[p + i];
	for(int i = 0; i < right_size; i++)
		right[i] = array[q + 1 + i];

	int i = 0, j = 0, k = 0;
	for(k = p; k < r; k++) {
		if(k == q) continue;
		if(i >= left_size || j >= right_size) break;
		if(left[i] <= right[j]) {
			array[k] = left[i];
			i++;
		} else {
			array[k] = right[j];
			j++;
		}
	}
	// Placer éléments pas encore placés. 
	// Exemple : [0 7] et [2 4 5], il restera 7 qui n'est pas mis car le j sur 2 4 5 dépassera 3 après avoir placé 5.
	// Un seul des deux doit être fini.
	while(i < left_size) { // Finir tableau de gauche.
		if(k == q) k++;
		array[k] = left[i];
		k++;
		i++;
	}
	while(j < right_size) { // Sinon Finir tableau de droite.
		if(k == q) k++;
		array[k] = right[j];
		k++;
		j++;
	}
}

void swap(int *array, int a, int b){
    int tmp = array[b];
    array[b] = array[a];
    array[a] = tmp;
}
