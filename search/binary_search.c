#include "binary_search.h"

bool binary_search(int *array, const int size, const int value)
{
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int ix = (low + high) / 2;
        if (value < array[ix]) {
            high = ix - 1;
        } else if (value > array[ix]) {
            low = ix + 1;
        } else {
            return true;
        }
    }

    return false;
}

