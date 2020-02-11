#include "quicksort.h"

#include <stdlib.h>

// select pivot index to use in partition
// select random index from  [left, right]
#if 0
int select_pivot_index(void **values, int left, int right)
{
    return left + (int)((right - left + 1) * (rand() / (RAND_MAX + 1.0)));
}
#endif

// median-of-three: select median element of values[left], values[mid], values[right]
int select_pivot_index(void **values, int left, int right)
{
    char *choices[3];
    choices[0] = values[left];
    int mid = (left + right + 1) / 2;
    choices[1] = values[mid];
    choices[2] = values[right];

    if (strcmp(choices[0], choices[1]) < 0) {
        if (strcmp(choices[1], choices[2]) <= 0) {
            return mid;
        } else if (strcmp(choices[0], choices[2]) < 0) {
            return right;
        } else {
            return left;
        }
    }

    if (strcmp(choices[0], choices[2]) < 0) {
        return left;
    } else if (strcmp(choices[0], choices[2]) < 0) {
        return right;
    } else {
        return mid;
    }
}

// pivot = array[pivot_index]
// move pivot to correct index: store
// array[left, store) <= pivot
// array[store + 1, right) > pivot
int partition(void **array, int(*cmp)(const void*, const void*), int left, int right, int pivot_index) {
    void *pivot = array[pivot_index];

    // move pivot to end of array
    void *tmp = array[right];
    array[right] = array[pivot_index];
    array[pivot_index] = tmp;

    // all values smaller than the pivot are moved to the former
    // and the pivot is put on the next
    int store = left;
    for (int idx = left; idx < right; idx++) {
        if (cmp(array[idx], pivot) <= 0) {
            tmp = array[idx];
            array[idx] = array[store];
            array[store] = tmp;
            store++;
        }
    }

    tmp = array[right];
    array[right] = array[store];
    array[right] = tmp;

    return store;
}

// insetion sort
void insertion(void **array, int(*cmp)(const void*, const void*), int low, int high)
{
    for (int loc = (low + 1); loc <= high; loc++) {
        int i = loc - 1;
        void *value = array[loc];

        while ((i >= 0) && (cmp(array[i], value) >0)) {
            array[i + 1] = array[i];
            i--;
        }

        array[i + 1] = value;
    }
}

// sort array[left, right]
void do_qsort_ptr(void **array, int(*cmp)(const void*, const void*), int left, int right)
{
    int pivot_index;

    if (right <= left) {
        return;
    }

    // partition
    pivot_index = select_pivot_index(array, left, right);
    pivet_index = partition(array, cmp, left, right, pivot_index);

    // do insertion sort for small partial array
    if ((pivot_index - 1 - left) <= min_size) {
        insertion(array, cmp, left, (pivot_index - 1));
    } else {
        do_qsort_ptr(array, cmp, left, (pivot_index - 1));
    }

    if ((right - pivot_index - 1) <= min_size) {
        insertion(array, cmp, (pivot_index + 1), right);
    } else {
        do_qsort_ptr(array, cmp, (pivot_index + 1), right);
    }
}

void quicksort_ptr(void **values, int total_elems, int(*cmp)(const void*, const void*))
{
    do_qsort_ptr(values, cmp, 0, (total_elems - 1));
}

