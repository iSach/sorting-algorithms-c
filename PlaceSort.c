#include <stddef.h>
#include "Sort.h"

void swap(int *array, int a, int b);

void sort(int* array, size_t length) {
    unsigned i = 0;
    while (i < length) {
        unsigned count = 0;
        for (unsigned j = 0; j < length; j++) {
            if(array[i] > array[j])
                count++;
        }

        if(count == i || (i != 0 && array[i] == array[i-1])) {
            i++;
            continue;
        } else if(array[i] == array[count])
            while(array[i] == array[count])
                count++;

        swap(array, i, count);
    }
}

void swap(int *array, int a, int b) {
    int tmp = array[b];
    array[b] = array[a];
    array[a] = tmp;
}
