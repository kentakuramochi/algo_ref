#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "insertion_sort.h"

void insertion_sort_val(void *array, const size_t size, const size_t n, int(*cmp)(const void*, const void*))
{
    // tmp area for swap
    void *saved = malloc(size);

    for (int i = 0; i < n; i++) {
        int j = i - 1;
        void *value = array + i * size;
        // mark larger value than pivot
        while ((j >= 0) && (cmp((array + j * size), value) > 0)) {
            j--;
        }
        if (++j == i) {
            continue;
        }

        // swap values
        memmove(saved, value, size);
        memmove((array + (j + 1) * size), (array + j * size), (size * (j - 1)));
        memmove((array + j * size), saved, size);
    }

    free(saved);
}

void insertion_sort_ptr(void **array, const size_t n, int(*cmp)(const void*, const void*))
{
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        void *value = array[i];
        while ((j >= 0) && (cmp(array[j], value) > 0)) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = value;
    }
}
