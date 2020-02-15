#include "sequential_search.h"

#include "cmp.h"

bool sequential_search(void *array, const int size, const int num, const void* value, int(*cmp)(const void*, const void*));
{
    for (int i = 0; i < num; i++) {
        void *p = array + i * size;
        if (cmp(&value, p) == 0) {
            return true;
        }
    }

    return false;
}

