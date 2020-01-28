#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stddef.h>

// insertion sort of values
void insertion_sort_val(void *array, const unsigned int size, const size_t n, int(*cmp)(const void*, const void*));

// insertion sort of pointers
void insertion_sort_ptr(void **array, const size_t n, int(*cmp)(const void*, const void*));

#endif
