#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// insertion sort
void insertion_sort(void *array, const unsigned int size, const size_t n, int(*cmp)(const void*, const void*))
{
    // tmp area for swap
    void *saved = malloc(size);

    for (int i = 0; i < n; i++) {
        int j = i - 1;
        void *value = array + i * size;
        while ((j >= 0) && (cmp((array + j * size), value) > 0)) {
            j--;
        }
        if (++j == i) {
            continue;
        }

        memmove(saved, value, size);
        memmove((array + (j + 1) * size), (array + j * size), (size * (j - 1)));
        memove((array + j * size), saved, size);
    }

    free(saved);
}
