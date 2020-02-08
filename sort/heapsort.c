#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heapsort.h"

static void heapify(void **array, int(*cmp)(const void*, const void*), int idx, int max)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest;

    if ((left < max) && (cmp(array[left], array[idx]) > 0)) {
        largest = left;
    } else {
        largest = idx;
    }

    if ((right < max) && (cmp(array[right], array[largest]) > 0)) {
        largest = right;
    }

    if (largest != idx) {
        void *tmp = array[idx];
        array[idx] = array[largest];
        array[largest] = tmp;

        heapify(array, cmp, largest, max);
    }
}

static void build_heap(void **array, int(*cmp)(const void*, const void*), int n)
{
    int i;
    for (int i = (n / 2 - 1); i >= 0; i--) {
        heapify(array, cmp, i, n);
    }
}

void heapsort_ptr(void **array, const size_t n, int(*cmp)(const void*, const void*))
{
    build_heap(array, cmp, n);

    for (int i = (n - 1); i >= 1; i--) {
        void *tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;

        heapify(array, cmp, 0, i);
    }
}
