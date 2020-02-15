#ifndef BINARY_SEARCH
#define BINARY_SEARCH

#include <stdbool.h>

bool binary_search(void *array, const int size, const int num, const void *value, int(*cmp)(const void*, const void*));

#endif

