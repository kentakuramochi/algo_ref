#ifndef SEQENTIAL_SEARCH
#define SEQENTIAL_SEARCH

#include <stdbool.h>

bool sequential_search(void *array, const int size, const int num, const void *value, int(*cmp)(const void*, const void*));

#endif

