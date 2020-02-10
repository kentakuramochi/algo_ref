#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "selectionsort.h"

static int select_max(void **array, int left, int right, int (*cmp)(const void*, const void *))
{
    int max_pos = left;
    int i = left;

    while (++i <= right) {
        if (cmp(array[i], array[max_pos]) > 0) {
            max_pos = i;
        }
    }

    return max_pos;
}

void selectionsort_ptr(void **array, int n, int (*cmp)(const void*, const void *))
{
    // find a max from array(0, i] and swap
    for (int i = (n - 1); i >= 1; i--) {
        int max_pos = select_max(array, 0, i, cmp);
        if (max_pos != i) {
            void *tmp = array[i];
            array[i] = array[max_pos];
            array[max_pos] = tmp;
        }
    }
}
