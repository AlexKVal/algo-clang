#include <stdlib.h>
#include "util.h"

#include <stdio.h> // DEBUG

typedef enum { false, true } bool;

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

size_t partition(int arr[], size_t first_idx, size_t last_idx) {
  size_t pivot_idx = last_idx; // last element as pivot version

  bool was_swap;

  do {
    was_swap = false;
    puts("> loop begin");

    size_t sub_arr_size = (last_idx - first_idx + 1);
    print_array(&arr[first_idx], sub_arr_size);

    for (size_t i = first_idx; i < pivot_idx; i++) {
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

        print_array(&arr[first_idx], sub_arr_size);

        pivot_idx = left_idx;
      }

      if (was_swap) break;
    }
    printf("\n");
  } while(was_swap && first_idx < pivot_idx);

  printf("result: %zu > %zu < %zu\n\n", first_idx, pivot_idx, last_idx);

  return pivot_idx;
}

void quick_sort(int arr[], size_t first_idx, size_t last_idx) {
  printf("quick_sort %zu..%zu\n", first_idx, last_idx);
  if (first_idx >= last_idx) return;

  size_t pivot_final_idx = partition(arr, first_idx, last_idx);

  if (pivot_final_idx == first_idx) return;

  size_t lower_part_final_idx = pivot_final_idx - 1;
  size_t higher_part_starting_idx = pivot_final_idx + 1;

  if ((lower_part_final_idx - first_idx) > 1) {
    printf("lower part\n");
    quick_sort(arr, first_idx, lower_part_final_idx);
  }

  if (higher_part_starting_idx != last_idx) {
    printf("higher part\n");
    quick_sort(arr, higher_part_starting_idx, last_idx);
  }
}

// cc quick-sort.c util.c && ./a.out
int main(int argc, const char *const argv[argc + 1]) {
  int arr[] = {5, 2, 3, 9, 0, 5, 2, 4, 4, 1};
  size_t arr_size = sizeof(arr) / sizeof(int);

  print_array_before(arr, arr_size);

  quick_sort(arr, 0, arr_size - 1);

  print_array_after(arr, arr_size);

  return EXIT_SUCCESS;
}
