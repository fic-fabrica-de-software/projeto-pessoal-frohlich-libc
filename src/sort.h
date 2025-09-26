#ifndef SORT_H
#define SORT_H

#define MIN_MERGE 32

#define sort(arr, size) \
    do { \
        if (arr && size > 1) { \
            timsort(arr, size); \
        } \
    } while(0)

void timsort(int* arr, unsigned long n);
void insertion_sort(int* left, int* right);
void merge(int* left, int* mid, int* right);
unsigned long min(unsigned long a, unsigned long b);

#endif
