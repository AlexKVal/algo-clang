#include <stdlib.h>
#include <stdio.h>
#include "util.h"

typedef enum { false, true } bool;

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void quick_sort(int arr[], size_t arr_size) {
  if (arr_size < 2) return;

  bool was_swap;
  size_t pivot_idx = arr_size - 1;

  do {
    was_swap = false;
    for (size_t i = 0; i < pivot_idx; i++) {
      if (arr[i] > arr[pivot_idx]) {
        if ((pivot_idx - 1) == i) {
          swap(&arr[pivot_idx - 1], &arr[pivot_idx]);
        } else {
          int tmp = arr[i];
          arr[i] = arr[pivot_idx - 1];
          arr[pivot_idx - 1] = arr[pivot_idx];
          arr[pivot_idx] = tmp;
        }
        was_swap = true;
        pivot_idx--;
      }
      if (was_swap) break;
    }
  } while(was_swap && 0 < pivot_idx);

  if (pivot_idx > 1)
    quick_sort(&arr[0], pivot_idx);

  if ((pivot_idx + 1) < arr_size - 1)
    quick_sort(&arr[pivot_idx + 1], arr_size - 1 - pivot_idx);
}

void quick_sort_verbose(int arr[], size_t arr_size) {
  printf("== quick_sort ==\n");
  if (arr_size < 2) return;

  size_t last_idx = arr_size - 1;

  bool was_swap;
  size_t pivot_idx = last_idx; // "last element as pivot" version

  do {
    was_swap = false;
    puts("> loop begin");
    print_array(arr, arr_size);

    for (size_t i = 0; i < pivot_idx; i++) {
      int nxt_val = arr[i];
      int pivot_val = arr[pivot_idx];
      printf("nxt: %d[%zu], pvt: %d[%zu]\n", nxt_val, i, pivot_val, pivot_idx);

      if (nxt_val > pivot_val) {
        // move the greater than pivot value to the right
        size_t left_idx = pivot_idx - 1;
        printf("lft: %d[%zu]\n", arr[left_idx], left_idx);

        if (left_idx == i) {
          // 2 swap | just swap left to the pivot value and pivot
          printf("2swap: %d %d\n", arr[left_idx], arr[pivot_idx]);
          swap(&arr[left_idx], &arr[pivot_idx]);
        } else {
          // 3 swap
          printf("3swap: %d ... %d %d\n", nxt_val, arr[left_idx], pivot_val);
          arr[i] = arr[left_idx]; // move left of the pivot value to the arr[i] (nxt_val)
          arr[left_idx] = pivot_val; // move pivot value to the left
          arr[pivot_idx] = nxt_val;
        }
        was_swap = true;
        pivot_idx = left_idx;

        print_array(arr, arr_size);
      }

      if (was_swap) break;
    }
    printf("\n");
  } while(was_swap && 0 < pivot_idx);

  printf("result: 0 > %zu < %zu\n\n", pivot_idx, last_idx);

  size_t sub_array_size;

  if (pivot_idx > 1) { // 0 1 [2]..
    printf("lower part\n");
    sub_array_size = pivot_idx;
    quick_sort(&arr[0], sub_array_size);
  }

  size_t high_first_idx = pivot_idx + 1;
  if (high_first_idx < last_idx) { // 0..[3] 4 5
    printf("higher part\n");
    sub_array_size = last_idx - pivot_idx;
    quick_sort(&arr[high_first_idx], sub_array_size);
  }
}

// cc quick-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  int arr[] = {5, 2, 3, 9, 0, 5, 2, 4, 4, 1};
  size_t arr_size = sizeof(arr) / sizeof(int);

  print_array_before(arr, arr_size);

  quick_sort(arr, arr_size);
  // quick_sort_verbose(arr, arr_size);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}