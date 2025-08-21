#ifndef SORT_H
#define SORT_H

#define MIN_MERGE 32

#define sort(arr) \
    do { \
        if (arr) { \
            unsigned long arr_size = 0; \
            int* temp_ptr = arr; \
            goto count_size; \
            count_size_return: \
            if (arr_size > 1) { \
                timsort(arr, arr_size); \
            } \
        } \
    } while(0)

static inline void timsort(int* arr, unsigned long n);
static inline void insertion_sort(int* left, int* right);
static inline void merge(int* left, int* mid, int* right);
static inline unsigned long min(unsigned long a, unsigned long b);

#endif