#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stddef.h>

// insertion sort of values
void insertionsort_val(void *array, const size_t size, const size_t n, int(*cmp)(const void*, const void*));

// insertion sort of pointers
void insertionsort_ptr(void **array, const size_t n, int(*cmp)(const void*, const void*));

#endif
