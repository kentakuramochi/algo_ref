#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void quicksort_ptr(void **values, int total_elems, int(*cmp)(const void*, const void*));

#endif
