#ifndef HEAPSORT_H 
#define HEAPSORT_H

#include <stddef.h>

void heapsort_ptr(void **array, const size_t n, int(*cmp)(const void*, const void*));

#endif
