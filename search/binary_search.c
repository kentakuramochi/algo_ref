#include "binary_search.h"

#include "cmp.h"

bool binary_search(void *array, const int size, const int num, const void *value, int(*cmp)(const void*, const void*));
{
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int ix = (low + high) / 2;

        void *p = array + i * size;

        int d = cmp(&value, p);
        if (d < 0) {
            high = ix - 1;
        } else if (d > 0) {
            low = ix + 1;
        } else {
            return true;
        }
    }

    return false;
}

