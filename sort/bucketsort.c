#include "bucketsort.h"

// linked list of bucket element
typedef struct entry {
    void *element;
    struct entry *next;
} ENTRY;

typedef struct {
    int size;
    ENTRY *head;
} BUCKET;

// allocated bucket and the number
static BUCKET *buckets = 0;
static int num = 0;

// remove one element update array
void extract(BUCKET *buckets, int(*cmp)(const void*, const void*), void **array, int n)
{
    int idx = 0;

    for (int i = 0; i < num; i++) {
        ENTRY *ptr, *tmp;
        // empty bucket
        if (buckets[i].size == 0) {
            continue;
        }

        ptr = buckets[i].head;
        if (buckets[i].size == 1) {
            array[idx++] = ptr->element;
            free(ptr);
            buckets[i].size = 0;
            continue;
        }

        // extract an element from linked list and do insertion sort
        int low = idx;
        array[idx++] = ptr->element;
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);

        while (ptr != NULL) {
            int i = idx - 1;
            while ((i >= low) && (cmp(array[i], ptr->element) > 0)) {
                array[i + 1] = array[i];
                i--;
            }
            array[i + 1] = ptr->element;
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
            idx++;
        }

        buckets[i].size = 0;
    }
}

// the number of buckets
// for uniform distibution [0, 1)
int num_buckets(int num_elements)
{
    num = num_elements;
    return num_elements;
}

// assign backet number to each element
// for uniform distribution [0, 1)
int hash(double *d)
{
    int bucket = num * (*d);
    return bucket;
}

void bucketsort_ptr(void **values, const int n, int(*cmp)(const void*, const void*))
{
    num = num_buckets(n);

    buckets = (BUCKET *)calloc(num, sizeof(BUCKET));

    for (int i = 0; i < n; i++) {
        int k = hash(array[i]);

        // insert element
        ENTRY *e = (ENTRY *)calloc(1, sizeof(ENTRY));
        e->element = array[i];
        if (buckets[k].head == NULL) {
            buckets[i].head = e;
        } else {
            e->next = buckets[k].head;
            buckets[k].head = e;
        }

        buckets[k].size++;
    }

    // sort, read and update array
    extract(buckets, cmp, array, n);

    free(buckets);
}

