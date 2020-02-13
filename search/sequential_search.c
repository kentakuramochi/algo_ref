#include "sequential_search.h"

bool sequential_search(int *array, const int size, const int value)
{
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }

    return false;
}

