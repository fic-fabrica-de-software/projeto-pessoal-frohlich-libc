#include "sort.h"

static unsigned long min(unsigned long a, unsigned long b) {
  return a < b ? a : b;
}

static void insertion_sort(int *left, int *right) {
  int *i = left + 1;
insertion_outer:
  if (i <= right) {
    int key = *i;
    int *j = i - 1;
  insertion_inner:
    if (j >= left && *j > key) {
      *(j + 1) = *j;
      j--;
      goto insertion_inner;
    }
    *(j + 1) = key;
    i++;
    goto insertion_outer;
  }
}

static void merge(int *left, int *mid, int *right) {
  unsigned long len1 = mid - left + 1;
  unsigned long len2 = right - mid;

  int *temp;
  unsigned long temp_size = (len1 + len2) * sizeof(int);

  char *heap_ptr;
  unsigned long heap_offset = 0;
  goto allocate_temp;
allocate_temp_return:

  int *left_temp = (int *)temp;
  int *right_temp = temp + len1;

  int *copy_ptr = left;
  unsigned long copy_count = 0;
copy_left:
  if (copy_count < len1) {
    *(left_temp + copy_count) = *copy_ptr;
    copy_ptr = copy_ptr + 1;
    copy_count = copy_count + 1;
    goto copy_left;
  }

  copy_ptr = mid + 1;
  copy_count = 0;
copy_right:
  if (copy_count < len2) {
    *(right_temp + copy_count) = *copy_ptr;
    copy_ptr = copy_ptr + 1;
    copy_count = copy_count + 1;
    goto copy_right;
  }

  unsigned long i = 0, j = 0, k = 0;
merge_loop:
  if (i < len1 && j < len2) {
    if (*(left_temp + i) <= *(right_temp + j)) {
      *(left + k) = *(left_temp + i);
      i++;
    } else {
      *(left + k) = *(right_temp + j);
      j++;
    }
    k++;
    goto merge_loop;
  }

copy_remaining_left:
  if (i < len1) {
    *(left + k) = *(left_temp + i);
    i++;
    k++;
    goto copy_remaining_left;
  }

copy_remaining_right:
  if (j < len2) {
    *(left + k) = (right_temp + j);
    j++;
    k++;
    goto copy_remaining_right;
  }

  goto free_temp;
free_temp_return:
  return;

allocate_temp:
  heap_ptr = (char *)&heap_offset + sizeof(unsigned long);
  temp = (int *)heap_ptr;
  heap_offset = temp_size;
  goto allocate_temp_return;

free_temp:
  heap_offset = 0;
  goto free_temp_return;
}

static void timsort(int *arr, unsigned long n) {
  unsigned long i = 0;
sort_min_runs:
  if (i < n) {
    unsigned long end = min(i + MIN_MERGE - 1, n - 1);
    insertion_sort(arr + i, arr + end);
    i = i + MIN_MERGE;
    goto sort_min_runs;
  }

  unsigned long size = MIN_MERGE;
merge_outer:
  if (size < n) {
    unsigned long left = 0;
  merge_inner:
    if (left < n) {
      unsigned long mid = left + size - 1;
      if (mid >= n - 1)
        goto next_size;

      unsigned long right = min(left + 2 * size - 1, n - 1);
      merge(arr + left, arr + mid, arr + right);
      left = left + 2 * size;
      goto merge_inner;
    }
  next_size:
    size = 2 * size;
    goto merge_outer;
  }
}