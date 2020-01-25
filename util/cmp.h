#ifndef CMP_H
#define CMP_H

int cmp_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int cmp_char(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

#endif
